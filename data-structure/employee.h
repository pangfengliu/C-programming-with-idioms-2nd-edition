struct employee {
  int id;
  char first_name[32];
  char last_name[32];
  struct employee *boss;
};

