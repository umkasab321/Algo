#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<list>
#include<random>
using namespace std;
using Point = pair<int, int>;
typedef struct tagPoint_t{
    int x;
    int y;
    bool flg;
} Point_t;
bool cmpX(const Point_t &a, const Point_t &b){
    return a.x < b.x;
}
bool cmpY(const Point_t &a, const Point_t &b){
    return a->y > b.y;
}
int main(){
    random_device rd{};
    cout << rd() % 50 << endl;
    int N = 10;
//    vector<Point> blue(N), red(N);
    vector<Point_t> blue(N), red(N);
    vector<Point_t> pt(2*N);
    for(int i = 0; i < N; i++){
        blue[i].x = rd () % 50;
        blue[i].y= rd () % 50;
        blue[i].flg = 0;
        red[i].x  = rd () % 50;
        red[i].y = rd () % 50;
        red[i].flg = 0;
        //cout << blue[i].x << ", " << blue[i].y << ", " << red[i].x << ", " << red[i].y << endl;

    }

    for(int i = 0; i < N; i++){
        pt[i].x = rd() % 50;
        pt[i].y = rd() % 50;
        pt[i].flg = 0; //blue
        pt[i + N].x  = rd() % 50;
        pt[i + N].y = rd() % 50;
        pt[i + N].flg = 1; //red
        cout << pt[i].x << ", " << pt[i].y << ", " << pt[i].flg << endl <<  pt[i + N].x << ", " << pt[i + N].y << ", " << pt[i + N].flg << endl;
    }
    cout << "------------------------------------------------------------------------------" << endl;
    sort(pt.begin(), pt.end(), cmpX);
    for(int i = 0; i < 2*N; i++){
        cout << pt[i].x << ", " << pt[i].y << ", " << pt[i].flg << endl;
    }
    cout << "------------------------------------------------------------------------------" << endl;

    list<Point_t> redList;
    auto itr = redList.begin();
    for(int i = 0; i < 2*N; i++){
        if(pt[i].flg == 0){
//            
        }else if(pt[i].flg == 1){
            itr = lower_bound(redList.begin(), redList.end(), pt[i].y, cmpY);
            itr = redList.insert(itr, pt[i]);
            ++itr;
            for (auto i = redList.begin(); i != redList.end(); i++){
                cout << "-" << itr->x  << ", " << itr->y  << ", " << itr->flg  << "-" << endl;

            }
        }
        cout << pt[i].x << ", " << pt[i].y << ", " << pt[i].flg << endl;
    }
    
    cout << "hello" << endl;
    return 0;
}
