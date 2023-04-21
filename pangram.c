#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

bool ispangram(char *s) {
  int bit_set = 0x00000000;
  int i = 0;

  while(s[i] != '\0') {
    int value = tolower(s[i]) - 97;
    if (value >= 0 && value < 26){
      bit_set |= (1 << value); 		
    }
    i++;
  }

  return bit_set == 0x03ffffff;
}

int main() {
  size_t len;
  size_t read;
  char *line = NULL;
  while ((read = getline(&line, &len, stdin)) != -1) {
    if (ispangram(line))
      printf("%s", line);
  }

  if (ferror(stdin))
    fprintf(stderr, "Error reading from stdin");

  free(line);
  fprintf(stderr, "ok\n");
}
