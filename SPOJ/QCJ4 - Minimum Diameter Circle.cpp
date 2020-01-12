#include <bits/stdc++.h>
using namespace std;

#define dist2D(x1,y1,x2,y2)         ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2)   ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS                         1e-10
#define endl                        "\n"
#define FastIO                      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt","r",stdin)
#define FO                          freopen("out.txt","w",stdout)
#define fap(x)                      cout<<"WTH: "<<x<<endl
#define ff                          first
#define fof(i,x,y)                  for(int i=x;i<(int)y;i++)
#define fob(i,x,y)                  for(int i=x;i>=(int)y;i--)
#define INF                         1000000000
#define ld                          long double
#define ll                          long long
#define mem(x,y)                    memset(x,y,sizeof x)
#define mp                          make_pair
#define msi                         map<string,int>
#define mii                         map<int,int>
#define mis                         map<int,string>
#define MOD                         1000000007
#define PI                          acos(-1.0)
#define PQ                          priority_queue
#define pb                          push_back
#define pib                         pair<int,bool>
#define pii                         pair<int,int>
#define pll                         pair<ll,ll>
#define sfi(x)                      scanf("%d",&x)
#define sfii(x,y)                   scanf("%d%d",&x,&y)
#define sfiii(x,y,z)                scanf("%d%d%d",&x,&y,&z)
#define siz(x)                      (int)x.size()
#define sortv(v)                    sort(v.begin(),v.end())
#define ss                          second
#define ull                         unsigned long long
#define umsi                        unordered_map<string,int>
#define umii                        unordered_map<int,int>
#define umis                        unordered_map<int,string>
#define vb                          vector<bool>
#define vi                          vector<int>
#define vvi                         vector<vi>
#define vii                         vector<pii>
#define vvii                        vector<vii>
#define vll                         vector<ll>
#define vpll                        vector<pll>

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;

//os.order_of_key(v): returns how many elements strictly less than v
//os.find_by_order(k-1): returns kth smallest element's iterator
*/

template<class T> class compare{
public:
    bool operator()(pair<T,T> &x,pair<T,T> &y){
        if(x.first==y.first){
            return x.ss>y.ss;
        }
        return x.ff>y.ff;
    }
};

template<class T> ostream& operator<<(ostream &os,const pair<T,T> &a) {
    os<<a.ff<<" "<<a.ss;
    return os;
}
ll power(ll a,int b){
    ll po=1;
    while(b){
        if(b&1)
            po*=a;
        a*=a;
        b>>=1;
    }
    return po;
}

template<class T> pair<T,T> operator+(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff+b.ff,a.ss+b.ss}; }
template<class T> pair<T,T> operator-(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff-b.ff,a.ss-b.ss}; }
template<class T> pair<T,T> operator*(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff*b.ff,a.ss*b.ss}; }
template<class T> pair<T,T> operator%(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff%b.ff,a.ss%b.ss}; }
template<class T,class U> pair<T,T> operator+(const pair<T,T> &a,const U &b){ return { a.ff+b,a.ss+b}; }
template<class T,class U> pair<T,T> operator*(const pair<T,T> &a,const U &b){ return { a.ff*b,a.ss*b}; }

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

///=======================================template=======================================///

class Point{
public:
    double x,y;
    Point(){ x=y=0.0; }
    Point(double _x,double _y):x(_x),y(_y) { }

    bool operator < (Point &outer) const{
        if(abs(x-outer.x)>EPS){
            return x<outer.x;
        }
        return y<outer.y;
    }

    bool operator == (const Point &outer) const{
        return (abs(x-outer.x)<EPS && abs(y-outer.y)<EPS);
    }
    Point operator + (const Point &p){ return {x+p.x,y+p.y};}
    Point operator - (const Point &p){ return {x-p.x,y-p.y};}
    Point operator * (double c){ return {x*c,y*c};}
    Point operator / (double c){ return {x/c,y/c};}
};

ostream& operator <<(ostream &os,Point &outer){
    os<<fixed<<setprecision(2)<<outer.x<<" "<<outer.y;
    return os;
}

double dot(Point p,Point q){ return p.x*q.x+p.y*q.y;}
double dist2(Point p,Point q){ return dot(p-q,p-q);}

double dist(Point a,Point b){
    return hypot(a.x-b.x,a.y-b.y);
}

Point rotateCCW(Point p,double theta){
    double rad=PI/180.0*theta;
    return {p.x*cos(rad)-p.y*sin(rad),p.x*sin(rad)+p.y*cos(rad)};
}

///===========================line===========================

class Line{
public:
    double a,b,c;
};

ostream& operator<<(ostream &os,Line l ){
    os<<fixed<<setprecision(2)<<l.a<<"x+"<<l.b<<"y"<<"+("<<l.c<<") = 0";
    return os;
}

void lineFromGradient(Point p,double grad,Line &l){
    l.a=-grad;
    l.b=1.0;
    l.c=-p.y+grad*p.x;
}

void pointstoLine(Point p1,Point p2,Line &l){
    if(abs(p1.x-p2.x)<EPS){
        l.a=1.0, l.b=0.0,l.c=-p1.x;
    }
    else{
        l.a=-(p1.y-p2.y)/(p1.x-p2.x);
        l.b=1.0;
        l.c=-(l.a*p1.x)-p1.y;
    }
}

bool areParallel(Line l1,Line l2){
    return (abs(l1.a-l2.a)<EPS && abs(l1.b-l2.b)<EPS);
}

bool areSame(Line l1,Line l2){
    return areParallel(l1,l2) && (abs(l1.c-l2.c)<EPS);
}

bool areIntersect(Line l1,Line l2,Point &p){
    if(areParallel(l1,l2)) return false;

    p.x=(l2.b*l1.c-l1.b*l2.c)/(l2.a*l1.b-l1.a*l2.b);
    if(abs(l1.b)>EPS) p.y=-(l1.a*p.x+l1.c);
    else p.y=-(l2.a*p.x+l2.c);
    return true;
}

void closestPoint(Line l,Point p, Point &ans){
    Line perpendicular;
    if(abs(l.b)<EPS){
        ans.x=-l.c,ans.y=p.y; return;
    }
    if(abs(l.a)<EPS){
        ans.x=p.x,ans.y=-l.c; return;
    }

    lineFromGradient(p,1/l.a,perpendicular);
    areIntersect(l,perpendicular,ans);
}

///============vector&circle===================

class Vector{
public:
    double x,y;
    Vector(double _x,double _y):x(_x),y(_y){}
};

Vector toVec(Point a,Point b){
    return {b.x-a.x,b.y-a.y};
}

Vector scale(Vector v, double s){
    return {v.x*s,v.y*s};
}

Point translate(Point p,Vector v){
    return {p.x+v.x,p.y+v.y};
}

double dot(Vector a,Vector b){ return (a.x*b.x+a.y*b.y);}
double magnitude_sqr(Vector v){ return v.x*v.x+v.y*v.y; }

double distToLine(Point p,Point a,Point b,Point &c){
    Vector ap=toVec(a,p),ab=toVec(a,b);
    double u=dot(ab,ap)/magnitude_sqr(ab);///notice: magnitude_sqr
    c=translate(a,scale(ab,u));
    return dist(p,c);
}

double distToLineSegment(Point p,Point a,Point b, Point &c){
    Vector ap=toVec(a,p),ab=toVec(a,b);
    double u=dot(ap,ab)/magnitude_sqr(ab);
    if(u<=0.0){
        c=Point(a.x,a.y);
        return dist(p,a);
    }
    if(u>=1.0){
        c=Point(b.x,b.y);
        return dist(p,b);
    }
    return distToLine(p,a,b,c);
}

double angle(Point a,Point o,Point b){
    Vector oa=toVec(o,a),ob=toVec(o,b);
    return acos(dot(oa,ob)/sqrt(magnitude_sqr(oa)*magnitude_sqr(ob)));
}

double cross(Vector a,Vector b){
    return a.x*b.y-a.y*b.x;
}

///may get changed if needed
bool ccw(Point p,Point q,Point r){
    return cross(toVec(p,q),toVec(p,r))>0;
}

bool collinear(Point p,Point q,Point r){
    return abs(cross(toVec(p,q),toVec(p,r)))<EPS;
}

///==================Circle=================

int insideCircle(Point p, Point center,double r){
    double dis=dist(p,center);
    return abs(dis-r)<EPS? 1 : (dis<r? 0: 2);
    ///0:inside, 1:on border, 2: outside
}

double chordLength(double r,double ang){
    return 2*r*sin(ang/2);
}

double sectorArea(double r,double ang){
    return (ang/(PI*2))*PI*r*r;
}

double segmentArea(double r,double ang){
    double sArea=sectorArea(r,ang);
    double triArea=0.5*r*r*sin(ang);
    return sArea-triArea;
}

bool circle2PtsRadius(Point p1,Point p2,double r,Point &c){
    double dis2=dist2(p1,p2);
    double det=r*r/dis2-0.25;

    if(det<0.0) return false;
    double h=sqrt(det);
    c.x=(p1.x+p2.x)*0.5+(p1.y-p2.y)*h;
    c.y=(p1.y+p2.y)*0.5+(p2.x-p1.x)*h;
    return true;
    /* https://math.stackexchange.com/questions/1781438/finding-the-center-of-a-circle-given-two-points-and-a-radius-algebraically
     * after drawing two circles like in the link and right triangle..., we can get the logic of getting center
     * other center can be found swapping p1 and p2
     */
}

bool circleCenter(Point p1,Point p2, Point p3,Point &ctr){
    Point m1=(p1+p2)/2;
    Point m2=(p1+p3)/2;
    if(collinear(p1,p2,p3)) return false;

    Line l1,l2;
    if(abs(p1.y-p2.y)<EPS){
        l1.a=1.0,l1.b=0.0,l1.c=-m1.x;
    }
    else{
        double grad;
        if(fabs(p1.x-p2.x)<EPS){
            grad=0.0;
        }
        else {
            grad=(p1.y-p2.y)/(p1.x-p2.x);
            grad=-1.0/grad;
        }
        lineFromGradient(m1,grad,l1);
    }

    if(abs(p1.y-p3.y)<EPS){
        l2.a=1.0,l2.b=0.0,l2.c=-m2.x;
    }
    else{
        double grad;
        if(fabs(p1.x-p3.x)<EPS){
            grad=0.0;
        }
        else {
            grad=(p1.y-p3.y)/(p1.x-p3.x);
            grad=-1.0/grad;
        }
        lineFromGradient(m2,grad,l2);
    }
    /* alternative:
    Line l1,l2;
    pointstoLine(m1,m1+rotateCCW(p1-m1,270),l1);
    pointstoLine(m2,m2+rotateCCW(p1-m2,270),l2);
     */

    areIntersect(l1,l2,ctr);

    return true;


}

void reflectionPoint(Line l,Point p,Point &ans){
    Point temp;
    closestPoint(l,p,temp);
    Vector v=toVec(p,temp);
    ans=translate(translate(p,v),v);
}

///==================triangle==================

double area(double ab,double bc,double ca){
    double s=(ab+bc+ca)/2.0;
    double val=s*(s-ab)*(s-bc)*(s-ca);
    if(val>=0.0){
        return sqrt(val);
    }
    else return -INF;
}

double rIncircle(double ab,double bc,double ca){
    return area(ab,bc,ca)/(0.5*(ab+bc+ca));
}

int inCircle(Point p1,Point p2,Point p3,Point &c,double &r){
    r=rIncircle(dist(p1,p2),dist(p2,p3),dist(p3,p1));
    if(abs(r)<EPS) return 0;

    Line l1,l2;
    double ratio=dist(p1,p2)/dist(p1,p3);

    Point p=translate(p2,scale(toVec(p2,p3),ratio/(1+ratio)));
    pointstoLine(p1,p,l1);

    ratio=dist(p2,p1)/dist(p2,p3);
    p=translate(p1,scale(toVec(p1,p3),ratio/(1+ratio)));
    pointstoLine(p2,p,l2);

    areIntersect(l1,l2,c);
    return 1;
}

double rCircumCircle(double ab,double bc,double ca){
    return ab*bc*ca/(4.0*area(ab,bc,ca));
}

int circumCircle(Point p1,Point p2,Point p3,Point &c,double &r){
    if(collinear(p1,p2,p3)) return 0;

    circleCenter(p1,p2,p3,c);
    r=dist(c,p1);

    return 1;
}

bool inCircumCircle(Point A,Point B,Point C,Point p){
    Point ctr;
    double r;
    if(circumCircle(A,B,C,ctr,r)==1){
        if(dist(ctr,p)<=r){
            return true;
        }
    }
    return false;
}

///=====================Polygon==================

double perimeter(const vector< Point > &points){
    double result=0.0;

    for(int i=0;i<(int)points.size()-1;i++){
        result+=dist(points[i],points[i+1]);
    }
    return result;
}

double area(const vector<Point> &points){
    double result=0.0;

    for(int i=0;i<(int)points.size()-1;i++){
        result+=(points[i].x*points[i+1].y-points[i+1].x*points[i].y);
    }
    return abs(result)/2.0;
}

bool isConvex(const vector<Point> &points){
    int sz=siz(points);
    if(sz<=3) return false;
    bool isLeft=ccw(points[0],points[1],points[2]);

    for(int i=1;i<sz-1;i++){
        if(ccw(points[i],points[i+1],points[(i+2)==sz? 1 : i+2])!=isLeft)
            return false;
    }
    return true;
}

bool inPolygon(Point pt,const vector<Point> &points){
    int sz=siz(points);

    if(sz==0) return false;
    double sum=0;

    for(int i=0;i<sz-1;i++){
        if(ccw(pt,points[i],points[i+1])){
            sum+=angle(points[i],pt,points[i+1]);
        }
        else sum-=angle(points[i],pt,points[i+1]);
    }

    return abs(abs(sum)-2*PI)<EPS;
}

vector<Point> cutPolygon(Point a,Point b,const vector<Point> &points){
    vector<Point> ans;

    for(int i=0;i<points.size();i++){
        double left1=cross(toVec(a,b),toVec(a,points[i])),left2=0;
        if(i!=(int) points.size()-1) left2=cross(toVec(a,b),toVec(a,points[i+1]));
        if(left1>-EPS) ans.push_back(points[i]);

        if(left1*left2<-EPS){
            Point intersection;
            Line l1,l2;
            pointstoLine(a,b,l1);
            pointstoLine(points[i],points[i+1],l2);
            areIntersect(l1,l2,intersection);
            ans.push_back(intersection);
        }
    }
    if(!ans.empty()&&!(ans.back()==ans.front())){
        ans.push_back(ans.front());
    }

    return ans;
}

Point pivot;
double maxang=0,minang=PI;
bool flag;

///may get changed if needed
bool angleCmp(Point a,Point b){
    if(collinear(pivot,a,b)){

        //if(abs(pivot.y-a.y)<EPS)
        //return dist(pivot,a)<dist(pivot,b);
        ///to neglect collinear points

        double tempang;
        if(a.x-pivot.x<EPS) tempang=PI-atan2(a.y-pivot.y,abs(a.x-pivot.x));
        else tempang=atan2(a.y-pivot.y,a.x-pivot.x);

        if(abs(tempang-maxang)<EPS) {
            //cout << a << endl;
            //cout << b << endl;
            return dist(pivot,a)>dist(pivot,b);
        };

        return dist(pivot,a)<dist(pivot,b);
    }

    double d1x=a.x-pivot.x,d1y=a.y-pivot.y;
    double d2x=b.x-pivot.x,d2y=b.y-pivot.y;
    return (atan2(d1y,d1x)-atan2(d2y,d2x))<0;
}

///may get changed if needed
vector<Point> convexHull(vector<Point> points){
    int j,sz=(int)points.size();

    if(sz<=3){
        if(!(points[0]==points[sz-1]))
            points.push_back(points[0]);
        return points;
    }

    int p0=0;

    for(int i=1;i<sz;i++){
        if(points[i].y<points[p0].y||(abs(points[i].y-points[p0].y)<EPS&&points[i].x>points[p0].x)){
            p0=i;
        }
    }

    Point temp=points[0];
    points[0]=points[p0];
    points[p0]=temp;

    pivot=points[0];

    for(int i=1;i<sz;i++){

        double tempang;
        if(points[i].x-pivot.x<EPS){
            tempang=PI-atan2(points[i].y-pivot.y,abs(points[i].x-pivot.x));
        }
        else tempang=atan2(points[i].y-pivot.y,points[i].x-pivot.x);

        maxang=max(maxang,tempang);
        minang=min(minang,tempang);
    }

    //cout << maxang * 180 / PI <<endl;

    sort(++points.begin(), points.end(),angleCmp);

    //cout <<points[0].x << " " << points[0].y << endl;
    //cout << points[points.size() - 1].x << " " << points[points.size() - 1].y << endl;

    vector<Point> ans;
    ans.push_back(points[sz-1]);
    ans.push_back(points[0]);
    ans.push_back(points[1]);

    int i=2;
    while(i<sz){
        j=(int) ans.size()-1;
        if(ccw(ans[j-1],ans[j],points[i]) or collinear(ans[j - 1], ans[j], points[i])) ans.push_back(points[i++]);
        else ans.pop_back();
    }
    return ans;
}

///=====================point3D=====================

class Point3D{
public:
    double x,y,z;
    Point3D(){x=y=z=0.0;}
    Point3D(double _x,double _y,double _z):x(_x),y(_y),z(_z){}
    void print() { cout << x << " " << y << " " << z << endl; }
};

double dist(Point3D &a,Point3D &b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

class Vector3D {
public:
    double x, y, z;
    Vector3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {
    }
    void print() { cout << x << " " << y << " " << z << endl; }
};

Vector3D toVec(Point3D a, Point3D b) {
    return {b.x - a.x, b.y - a.y, b.z - a.z};
}

double magnitude(Vector3D a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

double dot(Vector3D a, Vector3D b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

Vector3D scale(Vector3D v, double s){
    return {v.x * s, v.y * s, v.z * s};
}

Point3D translate(Point3D p,Vector3D v){
    return {p.x + v.x, p.y + v.y, p.z + v.z};
}

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {

        if (points.size() <= 3)
            return points;

        vector<Point> pts;
        for (auto &v : points) {
            pts.emplace_back((double)v[0], (double)v[1]);
        }

        vector<Point> cH = convexHull(pts);

        vvi ans(cH.size(), vi(2));
        int i = 0;
        for (auto &v : cH) {
            ans[i++][0] = llround(v.x);
            ans[i - 1][1] = llround(v.y);
        }
        if (ans[0] == ans[siz(ans) - 1])
            ans.pop_back();
        return ans;
    }
};

int main() {
    //FI;
    int n;
    cin >> n;
    double mini = 0;
    pair<double, double> points[n];
    for (auto &x : points) {
        cin >> x.ff >> x.ss;
    }

    double d = 1000, mul = 0.999;
    double mx = 0;
    Point center = {0, 0};
    int cnt = 0;

    while (d > 1e-7) {
        cnt++;
        int id = -1;
        mx = 0;

        for (int i = 0; i < n; i++) {
            if (dist(center, {points[i].ff, points[i].ss}) > mx) {
                mx = dist(center, {points[i].ff, points[i].ss});
                id = i;
            }
        }
        Vector vec = toVec(center, {points[id].ff, points[id].ss});
        center = translate(center, scale(vec, d / mx));
        d *= mul;
    }

    //cout << cnt << endl;

    mx = 0;
    for (auto &x : points) {
        mx = max(mx, dist(center, {x.ff, x.ss}));
    }

    cout << fixed << setprecision(2);

    cout << 2 * mx << endl;

    return 0;
}
