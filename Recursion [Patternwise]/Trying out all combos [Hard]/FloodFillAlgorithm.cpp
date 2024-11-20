// Problem statement - Coding Ninjas
// Ninja has found his new passion for photography. He has clicked some really good photos but in one of his images, he doesn’t like the color of a particular region. So, he decides to change the color of that region. Can you help him with this task?
// The image is represented in the form of a 2D array of size M * N. Each pixel in the image is a positive integer. Ninja has given you the coordinates (row and column) of a certain pixel and the new color value. You need to replace the color of the given pixel and all adjacent same-colored pixels with the new color.

// Note:
// Two pixels are adjacent if they are connected to each other in any of the four directions: up, down, left, or right.
// Diagonal pixels are not considered adjacent.
  
// Example:
// Consider the image of size 4*4, shown below (left). Let the coordinates of the starting pixel are (1, 2) and the new color is 8. The starting pixel, highlighted with red color, has a pixel value of 3. 
// On replacing the given pixel and all adjacent same-colored pixels with the new color we get the new image, shown below (right). The modified pixels are highlighted with green color.

#include<bits/stdc++.h>
using namespace std;

void flood(vector<vector<int>> &image, int x, int y, int oldColor, int newColor, int n, int m){
    if(x<0 || y<0 || x == n || y == m || image[x][y] != oldColor)return;
    
    image[x][y] = newColor;
    flood(image, x+1, y, oldColor, newColor, n, m);
    flood(image, x-1, y, oldColor, newColor, n, m);
    flood(image, x, y+1, oldColor, newColor, n, m);
    flood(image, x, y-1, oldColor, newColor, n, m);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor, int n, int m){
    int oldColor = image[x][y];
    if(oldColor == newColor) return image;
    flood(image, x, y, oldColor, newColor, n, m);
    return image;
}

int main()
{
    vector<vector<int>> image = {{1, 1, 7, 5}, {1, 3, 3, 3}, {6, 5, 5, 3}, {2, 2, 3, 3}};
    int n = image.size();
    int m = image[0].size();
    int x = 1;
    int y = 2;
    int newColor = 8;
    vector<vector<int>> res = floodFill(image, x, y, newColor, n, m);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}
