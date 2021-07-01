/* 5-3-2021
Find Color of Chair
In a game the participants are made to sit on chairs of three colors Green, Orange, Blue in a big hall. A number of pair of six chairs are arranged opposite to each other and numbered as shown in the following image. In the image each pair of six chairs are separated by a gap that is chairs with number 1 to 12 is a pair, 13 to 24 is a pair and so on.
green chairs column - g
orange chairs column - o
blue chairs column - b
g   o   b       b   o   g
1   2   3       4   5   6
12  11  10      9   8   7

13  14  15      16  17  18
24  23  22      21  20  19

25  26  27      28  29  30
36  35  34      33  32  31

37  

The first chair is Green, second chair is Orange third chair is Blue in color, fourth is Blue, fifth is Orange and sixth is Green and then the colors of chairs are reversed so that color of chairs on opposite sides are same. The numbering of chairs are increasing from left to right in the first pair and is decreasing from left to right in the second pair. In this game a participant is called and given a chair number, ‘x’. He has to find the number of the chair opposite to ‘x’ and also find the color of ‘x’. For example, when ‘x’ is 30, print 31 and Green when ‘x’ is 46 print 39 and Blue.

Input Format

First line contains the chair number, ‘x’

Output Format

First line contain the chair ‘y’ number opposite to ‘x’

Next line contain the color of chair ‘y’ (Green or Orange or Blue)*/

#include <iostream>

int main(){
    int num;
    cin >> num;
    
    // n is the first two row equivalent of that number
    int n = num, count = 0;
    while(n > 12){
        count++;
        n -= 12;
    }

    int chair = (num) + ((6 - n) * 2) + 1;
    cout << chair << "\n";
    
    if(num % 6 == 0 || num % 6 == 1)
        cout << "Green";
    else if(num % 3 == 0 || num % 3 == 1)
        cout << "Blue";
    else
        cout << "Orange";
    
    return 0;
}