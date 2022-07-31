#include "bmpfunc.h"
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#ifdef TEST_FUNCGIVEN

int RGB2Gray(unsigned char red, unsigned char green, unsigned char blue){
	// this is a commonly used formula
	int gray = 0.2989 * red + 0.5870 * green + 0.1140 * blue;
	return gray;
}

#endif

//Modify below this line and use code from HW10 for IMGTOGRAY()

#ifdef TEST_IMGTOGRAY

BMPImage * ImgToGray(BMPImage * image){
	// use code from your HW10

  //int width = (image->header).width;
  //int height = (image->header).height;

	// allocate space for the image
	// the image has the same size
	// therefore the header has to stay the same
	// check for memory allocation failure
  BMPImage * grayImage = malloc(sizeof(BMPImage));
  if(grayImage == NULL)
  {
    printf("Error converting to Gray image\n");
    BMP_Free(image);
    return NULL;
  }
	
	//gray_image can be the name of the new image memory allotment
	//gray_image->header = image->header;
  grayImage -> header = image -> header;
	
	//Assign the the imagesize as height * width
	// (gray_image->header).imagesize = (gray_image->header).width*(gray_image->header).height;
  //(grayImage->header).imagesize = (grayImage->header).width * (grayImage->header).height;
	
	//check for data allocation failure using :
	//(gray_image->data = malloc(sizeof(unsigned char)*(gray_image->header).imagesize)) == NULL)
  if((grayImage->data = malloc(sizeof(unsigned char)*(grayImage->header).imagesize)) == NULL)
  {
    printf("Error converting to Gray image\n");
    BMP_Free(image);
    BMP_Free(grayImage);
    return NULL;
  }
	
  int pixel, grayVal;
	//Run loop for all pixels using height and width
	//convert each pixel of all channels to gray using the given RGB2GRAY function
	// gray_val = RGB2Gray(image -> data[pixel+2],image -> data[pixel + 1],	image -> data[pixel]);
	//assign values to all pixels of gray_image for each channel
	//gray_image->data[pixel+2] = gray_val;
	//gray_image->data[pixel+1] = gray_val;
	//gray_image->data[pixel] = gray_val;
	//pixel+=3 to move on to the next 3 channel combination
  for(pixel = 0; pixel < (grayImage->header).imagesize; pixel += 3)
  {
    grayVal = RGB2Gray(image -> data[pixel+2], image -> data[pixel+1], image -> data[pixel]);
    grayImage -> data[pixel+2] = grayVal;
    grayImage -> data[pixel+1] = grayVal;
    grayImage -> data[pixel] = grayVal;
  }
		
	//return the result
  return grayImage;
}

#endif

//Write your own code for Adaptive Thresholding Function
#ifdef TEST_ADAPTIVETHRESHOLDING

BMPImage * AdaptiveThresholding(BMPImage * grayImage, int radius, int epsilon){
 	// allocate space for the image
	// the image has the same size(height and width)
	// therefore the header has to stay the same
  BMPImage * adaptive = malloc(sizeof(BMPImage));
  if(adaptive == NULL)
  {
    return NULL;
  }

  adaptive->header = grayImage->header;
  // (gray_image->header).imagesize = (gray_image->header).width*(gray_image->header).height;
  if ((adaptive->data = malloc(sizeof(unsigned char)*(adaptive->header).imagesize)) == NULL)
  {
    fprintf(stderr, "Error allocating memory\n");
    BMP_Free(adaptive);
    return NULL;
  }

  int pixel = 0;
  int row, col, i, j; //loop variables
  int height = (adaptive->header).height;  //number of pixels (each pixel is 3 bytes)
  int width = (adaptive->header).width;  //number of pixels (each pixel in 3 bytes)
  //int rowSize = (adaptive->header).width * ((adaptive->header).bits / 8);  //number of bytes
  int topRow, botRow, leftCol, rightCol; //top row, bottom row, left column, right column
  int sum = 0;
  int count; //counts how many values were added
  int average; //average value of the neighborhood of pixels

  //Run a nested loop for all elements using height and width
  for(row = 0; row < height; row++)
  {
    for(col = 0; col < width; col++)
    {
    //Find the maximum of top row, bottom rpw, left column and right column using radius
      topRow = MAX(0, row - radius);
      botRow = MIN(height - 1, row + radius);
      leftCol = MAX(0, col - radius);
      rightCol = MIN(width - 1, col + radius);

    //Calculate the avergage of all pixels
    //Run loop from toprow to bottom row
    //Inside which run a loop from left column to right column
          //calculate the location of each pixel using (row2*width + col2)*3;
       	  //add all data values at every location point in data
	  //keep a counter for averaging
      count = 0;
      sum = 0;
      for(i = topRow; i <= botRow; i++)
      {
        for(j = leftCol; j <= rightCol; j++)
	{
	  pixel = (i * width + j) * 3;  //this calculation gives the location in the 1-D array of the pixel with the specied row and column
	  sum += grayImage->data[pixel];
	  count++;
	}
      }
      //pixel+=3;
    
      //Outside the second nested loop: 
      //calculate averge (using int)
      average = sum / count;

      pixel = (row * width + col) * 3;

      //check if average-epsilon is greater than grayImage->data[at that pixel point]
      //then assign adaptive thresholding image data as 0(black) for data value at pixel, pixel+1, pixel+2
      if(average - epsilon > grayImage->data[pixel])
      {  
        adaptive -> data[pixel+2] = 0;
        adaptive -> data[pixel+1] = 0;
        adaptive -> data[pixel] = 0;
      }
      // else if average is lower then color shall be white(255) for data value at pixel, pixel+1, pixel+
      else if(average - epsilon <= grayImage->data[pixel])
      {
        adaptive -> data[pixel+2] = 255;
        adaptive -> data[pixel+1] = 255;
        adaptive -> data[pixel] = 255;
      }
    }
  }

  //return the image after adaptive thresholding
  return adaptive;
}


#endif
