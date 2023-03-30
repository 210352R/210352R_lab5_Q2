#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


void printArr(vector<int> arr,float median,int sizeI,int sizeArr);
void insertionSort(vector<int> &arr){
    for(int i=1;i<arr.size();i++){
        int value = arr[i];
        int j = i;
        while(j>0 && arr[j-1]>=value){
            //int tmep = arr[j];
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = value;
    }
}


void getMedian(vector<int> arr){
    vector<int> temp;
    double median;

    cout<<setw((arr.size()*5)-2) <<left<<"Sorted"<<setw(5*arr.size())<<left<<"Median"<<endl;

    for(int i=0;i<arr.size();i++){

        temp.push_back(arr[i]);

        insertionSort(temp);

        int mid = (temp.size())/2;


        if(temp.size()==1){
            median = temp[0];
        }else if((temp.size()%2==1)){
            median = temp[mid];
        }else{
            median = (float)(temp[mid]+temp[mid-1])/2;
        }
        printArr(temp,median,i,arr.size());
    }
}


void printArr(vector<int> arr,float median,int sizeI,int sizeArr){
    cout<<"[";
    for(int i=0;i<arr.size();i++){

        cout<<arr[i]<<",";
    }
    int n = 5*sizeArr;
    cout<<"\b]"<<setw(n-arr.size()-(2*sizeI))<<right<<fixed<<setprecision(1)<<median<<endl;

}




int main()
{
    vector<int> arr={1,18,39,61,10,11};
    getMedian(arr);

    return 0;
}
