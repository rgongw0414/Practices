#include<bits/stdc++.h>

using namespace std;
#define endl '\n'

/* 
sample input:
6
1 3 0 5 5 8
1 1 6 2 4 1

sample output:
4
*/

int start(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    return 0;
}
static int ooo = start();

struct Workshops{
    int start_time;
    int duration;
    int end_time;
    
    friend bool operator < (Workshops a, Workshops b){
        return (a.end_time < b.end_time);
    }
};

 struct Available_Workshops{
    int n;
    vector<Workshops> arr;    
};

static int max_end = 0;
Available_Workshops* initialize(int * start_time, int* duration, int n){
    Available_Workshops* aw = new Available_Workshops;
    aw->n = n;
    Workshops arr;
    for (int i = 0; i < n; i++){
        arr.start_time = start_time[i];
        arr.duration = duration[i];
        arr.end_time = start_time[i] + duration[i];
        aw->arr.push_back(arr);
        if (arr.end_time > max_end) max_end = arr.end_time;
    }
    return aw;
}

int CalculateMaxWorkshops(Available_Workshops* ptr){    
    sort(ptr->arr.begin(), ptr->arr.end());
    vector<bool> List(max_end+1, true); 
    vector<bool> tmp;    
    int x = 0; // num of ws can attend
    for (int i = 0; i < ptr->n; i++){
        tmp = List;
        int f = 0;
        for (int x = ptr->arr[i].start_time; x < ptr->arr[i].end_time; x++){
            if (List[x] == true){
                f++;
                List[x] = false;
            }
            else {
                break;
            }
        }
        if (f != ptr->arr[i].end_time - ptr->arr[i].start_time){
            List = tmp; // return to prev stat                
        }
        if (f == ptr->arr[i].end_time - ptr->arr[i].start_time) {
            x++;
        }
    }
    return x;
}


//////////////////////////
//  brute-force method  //
//////////////////////////
// struct Available_Workshops{
//     int n;
//     Workshops* arr;    
// };

// static int max_end = 0;
// Available_Workshops* initialize(int * start_time, int* duration, int n){
//     Workshops* arr = new Workshops[n];
//     Available_Workshops* aw = new Available_Workshops;
//     for (int i = 0; i < n; i++){
//         arr[i].start_time = start_time[i];
//         arr[i].duration = duration[i];
//         arr[i].end_time = start_time[i] + duration[i];
//         if (arr[i].end_time > max_end) max_end = arr[i].end_time;
//     }
//     aw->arr = arr;
//     aw->n = n;
//     return aw;
// }

// static int MAX = 0;
// static vector<bool> List(max_end+1, true); 
// static vector<bool> tmp;
// void permute(Workshops* a, int l, int r, int n)
// {
//     // Base case
//     if (l == r){
//         int x = 0; // num of ws can attend
//         List.assign(max_end+1, true);
//         for (int i = 0; i < n; i++){
//             tmp = List;
//             int f = 0;
//             for (int x = a[i].start_time; x < a[i].end_time; x++){
//                 if (List[x] == true){
//                     f++;
//                     List[x] = false;
//                 }
//                 else {
//                     break;
//                 }
//             }
//             if (f != a[i].end_time - a[i].start_time){
//                 List = tmp; // return to prev stat                
//             }
//             else {
//                 x++;
//             }
//         }
//         if (x > MAX){
//             MAX = x;
//         }
//     }        
//     else
//     {
//         // Permutations made
//         for (int i = l; i <= r; i++)
//         {
//             // Swapping done
//             swap(a[l], a[i]);
 
//             // Recursion called
//             permute(a, l+1, r, n);
 
//             //backtrack
//             swap(a[l], a[i]);
//         }
//     }
// }

// int CalculateMaxWorkshops(Available_Workshops* ptr){    
//     permute(ptr->arr, 0, (ptr->n)-1, ptr->n);
//     return MAX;
// }

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
