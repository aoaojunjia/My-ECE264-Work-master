#include "hw11.h"
//Modify this file
#ifdef TEST_MAIN

int main(int argc, char **argv){
  // check the arguments - please read readme about validity of arguments
  if(argc != 5)
  {
    printf("Wrong arguments\n");
    return EXIT_FAILURE;
  }

  int radius = strtol(argv[3], NULL, 10);
  int epsilon = strtol(argv[4], NULL, 10);

  // check radius and epsilon values -  read readme for the validity of argument
  if(radius < 1 || epsilon < 1)
  {
    printf("Wrong inputs\n");
    return EXIT_FAILURE;
  }

  // open the BMP file
  BMPImage * image = BMP_Open(argv[1]);
  if(image == NULL)
  {
    return EXIT_FAILURE;
  }

  // convert to gray scale
	// check for error in converting to gray scale
  BMPImage * grayImage = ImgToGray(image);
  if(grayImage == NULL)
  {
    return EXIT_FAILURE;
  }

  // call adaptive threshold function
  /*BMPImage * adaptive = malloc(sizeof(BMPImage));
  if(adaptive == NULL)
  {
    printf("Malloc failed\n");
    BMP_Free(image);
    BMP_Free(grayImage);
    return EXIT_FAILURE;
  }*/

  BMPImage * adaptive = AdaptiveThresholding(grayImage, radius, epsilon);
  // check for errors after calling adaptive threshold
  if(adaptive == NULL)
  {
    printf("Error in Adaptive Gray image\n");
    return EXIT_FAILURE;
  }

  // write the adaptive threshold image to file
  if((BMP_Write(argv[2], adaptive)) != 1)
  {
    BMP_Free(adaptive);
    BMP_Free(image);
    BMP_Free(grayImage);
    return EXIT_FAILURE;
  }

  // free all the images
  BMP_Free(adaptive);
  BMP_Free(image);
  BMP_Free(grayImage);

  return EXIT_SUCCESS;
}

#endif
