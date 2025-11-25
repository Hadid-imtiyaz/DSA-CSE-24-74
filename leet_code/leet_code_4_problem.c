//PREPROCESSOR DIRECTORIES/MAIN FUCCTION NOT PRESENT//
int maxArea(int* height, int heightSize) {

    int left,maxArea=0,Area;

    left=0;
    --heightSize;

    while(left<heightSize)
    {
        Area=((height[left]<height[heightSize])? height[left]:height[heightSize])*(heightSize-left);
        if(Area>maxArea) maxArea=Area;

        height[left]<height[heightSize]? left++:heightSize--;
    }

    return maxArea;
    
}