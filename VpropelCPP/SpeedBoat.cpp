/*18 - 4 - 2021
Speed of a Boat
There was a mistake in description and there is a Change in Output Format

Apologies for that

A water current, in a river is the flow of water influenced by gravity as the water moves downhill to reduce its potential energy. Upstream is a water current which acts against the direction of the boat movement and downstream is a water current which acts in the same direction of the boat movement. In upstream, a boat travels in the river from one side to the other side in ‘x’ hours and in downstream it takes ‘y’ hours.

For example, if the time taken in upstream is 3 and time taken in downstream is 4 then the time taken by the boat without water current will be

3.428
Write a C++ program to find the time taken by the boat to move from one side to another without water current 

Input Format

First line contains the time taken by the boat in upstream

Next line contains the time taken by the boat in downstream

Output Format

Print time taken by boat

Note

Print floor of time taken by boat */

#include<iostream>
using namespace std;
int main()
{
    int ut,dt;
    cin >> ut >> dt;
    cout << (2*ut*dt)/(ut+dt);
}

/*
IN PYTHON
l=([int(input()) for i in range(2)])
print((int)(2*l[0]*l[1]/(l[0]+l[1])))
*/