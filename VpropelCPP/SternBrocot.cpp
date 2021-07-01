/*19 - 4 - 2021
Stern-Brocot Sequence
Stern-Brocot Sequence is a sequence similar to fibanocci series. A sequence ‘a’ is built using the following rules:
a0 = 0
a1 = 1
a2i = ai
a2i+1 = ai + ai+1
For example, the sequence of numbers 1, 1, 2, 1, 3 is a Stern-Brocot Sequence and 1, 1, 2, 1, 3, 2, 3, 3, 4 is not a Stern-Brocot Sequence since the eigth element is not as per rule. Given ‘n’ numbers write a C++ code to find out if it can be a Stern-Brocot Sequence when taken in order.
Input Format
First line contains the number of elements, n
Next line contains the elements separated by a space
Output Format
Print Yes if the elements form Stern-Brocot Sequence and print No and the index of the first element which violates the rule
*/
#include<iostream>
using namespace std;
int index = 0;
bool Stern_Brocot_Check(int arr[], int n);

int main()
{
    int n;
    cin >> n;
    
    int array[n];
    for(int i =0; i < n; i++)
        cin >> array[i];
        
    if(array[0] != 1){
        cout << "No\n1";
        return 0;
    }
    if(array[1] != 1){
        cout << "No\n2";
        return 0;
    }
        
    Stern_Brocot_Check(array, n) ? cout << "Yes" : cout << "No\n" << index + 1;
}

bool Stern_Brocot_Check(int arr[], int n){
    int arr2[n];
    index = 0;
    arr2[0] = arr[0]; arr2[1] = arr[1];
    for(int i = 2; i < n; i++){
        index = i;
        
        if(i%2==0)
            arr2[i] = arr2[i/2] + arr2[(i/2) - 1];
        else
            arr2[i] = arr2[(i-1)/2];
            
        if(arr2[i] != arr[i])
            return false;
    }
    
    cout << "\n";
    
    return true;
}