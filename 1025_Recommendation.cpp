#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Goods {
    int list;
    char id [10];
    int volume;
    double price;
} Goods;

double MedianVolume (vector<int> &arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    if (n % 2 == 0) {
        return (arr[n/2 - 1] + arr[n/2]) / 2;
    } else {
        return arr[n/2];
    }
}

double MedianPrice (vector<double> &arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    if (n % 2 == 0) {
        return (arr[n/2 - 1] + arr[n/2]) / 2;
    } else {
        return arr[n/2];
    }
}

int main (){
    int T;
    cin >> T;
    cin.ignore();
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        cin.ignore();
        Goods goods[n];
        Goods recommend[n];
        int count = 0;
        bool have = false;
        for (int j = 0; j < n; j++) {
            goods[j].list = j;
        }
        for (int j = 0; j < n; j++) {
            cin >> goods[j].id >> goods[j].volume >> goods[j].price;
        }
        vector<int> volumeArr;
        vector<double> priceArr;
        for (int j = 0; j < n; j++) {
            volumeArr.push_back(goods[j].volume); 
            priceArr.push_back(goods[j].price);
        }
        double medianVolume = MedianVolume(volumeArr);
        double medianPrice = MedianPrice(priceArr);
        for (int j = 0; j < n; j++) {
            if (goods[j].volume > medianVolume && goods[j].price < medianPrice) {
                recommend[count++] = goods[j];
                have = true;
            }
        }
        cout << "case #" << i << ":" << endl;
        if (have==false) {
            cout << "no recommendation" << endl;
        }
        else {
            for (int j = 0; j < count-1; j++) {
                for (int k = j+1; k < count; k++) {
                    if (recommend[j].volume < recommend[k].volume) {
                        swap(recommend[j], recommend[k]);
                    }
                    else if (recommend[j].volume == recommend[k].volume && recommend[j].price > recommend[k].price) {
                        swap(recommend[j], recommend[k]);
                    }
                    else if (recommend[j].price == recommend[k].price && recommend[j].list>recommend[k].list) {
                        swap(recommend[j], recommend[k]);
                    }
                }
            }
            for (int j = 0; j < count; j++) {
                cout << recommend[j].id << " " << recommend[j].volume << " " << recommend[j].price << endl;
            }
        }
    }
    return 0;
}