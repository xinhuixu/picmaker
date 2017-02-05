#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>

int main(){
  int fd, i, j, xres, yres; 
  xres = 256*2; yres = 256*2;
  fd = open("xd.ppm", O_CREAT | O_RDWR ,0777);
  
  char h[20]; snprintf(h, sizeof(h), "P3\n%d %d\n255\n", xres, yres);
  write(fd, h, strlen(h) * sizeof(char));
  
  /* all black */			
  /* for (i=0; i<yres; i++){ */
  /*   for (j=0; j<xres; j++) { */
  /*     char c[20]; */
  /*     sprintf(c, "%d %d %d ", 1,1,1); */
  /*     write(fd, c, strlen(c) * sizeof(char)); */
  /*   } */
  /* } */

  /* double vertical grayscale gradient */
  /* for (i=0; i<yres; i++){ */
  /*   for (j=0; j<xres; j++){ */
  /*     int n = j % 256; */
  /*     char c[20]; */
  /*     sprintf(c, "%d %d %d ", n, n, n); */
  /*     write(fd, c, strlen(c) * sizeof(char)); */
  /*   } */
  /* } */


  for (i=0; i<yres; i++){
    for (j=0; j<xres; j++){
      int n = j % 256;
      char c[20];

      if (j<(xres/2)){
	if ((j%2 == 0)){
	  sprintf(c, "%d %d %d ", n, (n*n)%256, (n*n*n)%256);
	} else {
	  sprintf(c, "%d %d %d ", n, n, n);	
	}
      } else {
	sprintf(c, "%d %d %d ", n, (n*n)%256, (n*n*n)%256);
      }
      
      write(fd, c, strlen(c) * sizeof(char));
    }
  }
  

  close(fd);

}
