// Threaded two-dimensional Discrete FFT transform
// Chris Turner
// cturner48@gatech.edu
// ECE8893 Project 2
// Additional code provided by
// George Riley, Georgia Institute of Technology


#include <iostream>
#include <string>
#include <math.h>

#include "Complex.h"
#include "InputImage.h"

// Global Variable Definitions
using namespace std;
string fn("Tower.txt"); // default file name
InputImage image(fn.c_str());  // Create the helper object for reading the image.
Complex* imgArr = image.GetImageData();
int height = image.GetHeight();
int width = image.GetWidth();
int N = sizeof(width * height); // N integer for number of entries in Array for ReverseBits.

unsigned ReverseBits(unsigned v)
{ //  Provided to students.
  unsigned n = N; // Size of array (which is even 2 power k value).
  unsigned r = 0; // Return value.
   
  for (--n; n > 0; n >>= 1)
    {
      r <<= 1;        // Shift return value.
      r |= (v & 0x1); // Merge in next bit.
      v >>= 1;        // Shift reversal value.
    }
  return r;
}

// GRAD Students implement the following 2 functions.
// Undergrads can use the built-in barriers in pthreads.

// Call MyBarrier_Init once in main
void MyBarrier_Init()// you will likely need some parameters)
{
}

// Each thread calls MyBarrier after completing the row-wise DFT
void MyBarrier() // Again likely need parameters
{
}
                    
void Transform1D(Complex* h, int N)
{
  // Implement the efficient Danielson-Lanczos DFT here.
  // "h" is an input/output parameter
  // "N" is the size of the array (assume even power of 2)
}

void* Transform2DTHread(void* v)
{ // This is the thread startign point.  "v" is the thread number
  // Calculate 1d DFT for assigned rows
  // wait for all to complete
  // Calculate 1d DFT for assigned columns
  // Decrement active count and signal main if all complete
  return 0;
}

void Transform2D(const char* inputFN) 
{ // Do the 2D transform here.
  // Create the global pointer to the image array data
  // Create 16 threads
  // Wait for all threads complete
  // Write the transformed data
  Transform1D(imgArr, N);
}

int main(int argc, char** argv)
{
  if (argc > 1) fn = string(argv[1]);  // if name specified on cmd line
  // MPI initialization here
  Transform2D(fn.c_str()); // Perform the transform.
}  
  

  
