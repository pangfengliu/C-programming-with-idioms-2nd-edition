#include <stdio.h>
#include <math.h>
#include <assert.h>

typedef struct note
{
  double frequency;
  double duration;
} Note;

typedef struct WAVheader
{
  char RIFF[4];
  int chunkSize;
  char wave[4];
  char format[4];
  int subChunkSize;
  short audioFormat;
  short numChannel;
  int sampleRate;
  int byteRate;
  short blockAlign;
  short bitsPerSample;
  char data[4];
  int dataSize;
} WAVHeader;

#define SAMPLE 65536
#define LOWFREQTHRESHOLD 100
#define MAGNIFYFACTOR 20000

#define min(a, b) (a < b? a:b)

int genWAV(Note note[], int n, FILE *fp, WAVHeader header)
{
  int i, j, noteNum;
  int dataSize = 0;
  const double PI = 3.1415926;
  short sample[SAMPLE];
  short zero[SAMPLE] = {0};

  for (noteNum = 0; noteNum < n; noteNum++) {
    int frequency = note[noteNum].frequency;
    int numOfSamples = 2 * note[noteNum].duration * header.sampleRate;

    if (frequency < LOWFREQTHRESHOLD) {
      int samplesToWrite = numOfSamples;
      while (samplesToWrite > 0) {
	fwrite(zero, sizeof(short), min(SAMPLE, samplesToWrite), fp);
	samplesToWrite -= SAMPLE;
      }
      dataSize += sizeof(short) * numOfSamples;
    }
    else {
      int samplePerCycle = header.sampleRate / (double)frequency;
      double duration = note[noteNum].duration * 2;
      int numCycle = (int)(duration * frequency);
      double delta = (2.0 * PI) / samplePerCycle;
    
      printf("%d samples per second\n", header.sampleRate);
      printf("%d samples per cycle\n", samplePerCycle);
      printf("%d cycles to write\n", numCycle);

      assert(samplePerCycle < SAMPLE);
      for (i = 0; i < samplePerCycle; i++) {
	sample[i] = sin(delta * i) * MAGNIFYFACTOR;
      }
      while 
      for (i = 0; i < numCycle; i++) {
	for (j = 0; j < samplePerCycle / header.blockAlign; 
	     j += header.blockAlign) {
	  fwrite(&(sample[j]), sizeof(short), header.blockAlign, fp);
	  fwrite(&(sample[j]), sizeof(short), header.blockAlign, fp);
	  dataSize += sizeof(short) * 2 * header.blockAlign;
	}
      }
    }
  }
  return dataSize;
}

#define MAXNOTE 1024

int main()
{
  WAVHeader header = {
    {'R', 'I', 'F', 'F'}, 0, {'W', 'A', 'V', 'E'}, {'f', 'm', 't', ' '},
    16, 1, 2, 44100, 176400, 4, 16, {'d', 'a', 't', 'a'}, 0
  };
  int dataSize = 0;
  Note note[MAXNOTE];

  int i = 0;
  while (scanf("%lf%lf", &(note[i].frequency), &(note[i].duration))!= EOF) {
    printf("%f %f\n", note[i].frequency, note[i].duration);
    i++;
  }
  
  FILE *fp;
  fp = fopen("sample.wav", "wb");
  fwrite(&header, sizeof(WAVHeader), 1, fp);

  dataSize = genWAV(note, i, fp, header);
  printf("dataSize = %d\n", dataSize);
  int chunkSize = dataSize + 36;
  printf("chunkSize = %d\n", chunkSize);
  fseek(fp, 4, SEEK_SET);
  fwrite(&chunkSize, sizeof(int), 1, fp);
  fseek(fp, 40, SEEK_SET);
  fwrite(&dataSize, sizeof(int), 1, fp);
  fclose(fp);
  return 0;
}
