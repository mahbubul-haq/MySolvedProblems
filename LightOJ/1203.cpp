#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define vi vector<int>
#define vvi vector<vi>02
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>
#define MOD 998244353
#define EPS 1e-12
#define mem(x,y) memset(x,y,sizeof x)
#define INF 1e9
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define PI acos(-1.0)

class compare{
public:
    bool operator()(pii x,pii y){
        if(x.second==y.second){
            return x.first<y.first;
        }
        return x.second<y.second;
    }
};

ostream& operator<<(ostream &os,const pll &a){
    os<<a.first<<" "<<a.second;
}

/*pll operator+(const pll &a, const ll &b){ return { a.first+b,a.second+b };}
pll operator*(const pll &a,const ll &b){ return {a.first*b,a.second*b};}
pll operator+(const pll &a,const pll &b){ return {a.first+b.first,a.second+b.second};}
pll operator-(const pll &a,const pll &b){ return { a.first-b.first,a.second-b.second};}
pll operator*(const pll &a,const pll &b){ return {a.first*b.first,a.second*b.second};}
pll operator%(const pll &a,const pll &b){ return {a.first%b.first,a.second%b.second};}*/

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

///=======================================template=======================================///

class Point{
public:
    double x,y;
    Point(){ x=y=0.0; }
    Point(double _x,double _y):x(_x),y(_y) { }
    Point(const Point &p):x(p.x),y(p.y){}

    bool operator < (Point &outer) const{
        if(fabs(x-outer.x)>EPS){
            return x<outer.x;
        }
        return y<outer.y;
    }

    bool operator == (const Point &outer) const{
        return (fabs(x-outer.x)<EPS&&fabs(y-outer.y)<EPS);
    }
    Point operator + (const Point &p){ return Point(x+p.x,y+p.y);}
    Point operator - (const Point &p){ return Point(x-p.x,y-p.y);}
    Point operator * (double c){ return Point(x*c,y*c);}
    Point operator / (double c){ return Point(x/c,y/c);}
};

ostream& operator <<(ostream &os,Point outer){
    os<<(int)round(outer.x)<<" "<<(int)round(outer.y);
}

double dot(Point p,Point q){ return p.x*q.x+p.y*q.y;}
double dist2(Point p,Point q){ return dot(p-q,p-q);}

double dist(Point a,Point b){
    return hypot(a.x-b.x,a.y-b.y);
}

Point rotateCCW(Point p,double theta){
    double rad=acos(-1.0)/180.0*theta;
    return Point(p.x*cos(rad)-p.y*sin(rad),p.x*sin(rad)+p.y*cos(rad));
}

///===========================line===========================

class Line{
public:
    double a,b,c;
};

ostream& operator<<(ostream &os,Line l ){
    os<<fixed<<setprecision(2)<<l.a<<"x+"<<l.b<<"y"<<"+("<<l.c<<") = 0";
}

void lineFromGradient(Point p,double grad,Line &l){
    l.a=-grad;
    l.b=1.0;
    l.c=-p.y+grad*p.x;
}

void pointstoLine(Point p1,Point p2,Line &l){
    if(fabs(p1.x-p2.x)<EPS){
        l.a=1.0, l.b=0.0,l.c=-p1.x;
    }
    else{
        l.a=-(p1.y-p2.y)/(p1.x-p2.x);
        l.b=1.0;
        l.c=-(l.a*p1.x)-p1.y;
    }
}

bool areParallel(Line l1,Line l2){
    return (fabs(l1.a-l2.a)<EPS&&fabs(l1.b-l2.b)<EPS);
}

bool areSame(Line l1,Line l2){
    return areParallel(l1,l2)&&(fabs(l1.c-l2.c)<EPS);
}

bool areIntersect(Line l1,Line l2,Point &p){
    if(areParallel(l1,l2)) return false;

    p.x=(l2.b*l1.c-l1.b*l2.c)/(l2.a*l1.b-l1.a*l2.b);
    if(fabs(l1.b)>EPS) p.y=-(l1.a*p.x+l1.c);
    else p.y=-(l2.a*p.x+l2.c);
    return true;
}

void closestPoint(Line l,Point p, Point &ans){
    Line perpendicular;
    if(fabs(l.b)<EPS){
        ans.x=-l.c,ans.y=p.y; return;
    }
    if(fabs(l.a)<EPS){
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
    return Vector(b.x-a.x,b.y-a.y);
}

Vector scale(Vector v, double s){
    return Vector(v.x*s,v.y*s);
}

Point translate(Point p,Vector v){
    return Point(p.x+v.x,p.y+v.y);
}

double dot(Vector a,Vector b){ return (a.x*b.x+a.y*b.y);}
double magnitude_sqr(Vector v){ return v.x*v.x+v.y*v.y; }

double distToLine(Point p,Point a,Point b,Point &c){
    Vector ap=toVec(a,p),ab=toVec(a,b);
    double u=dot(ab,ap)/magnitude_sqr(ab);
    c=translate(a,scale(ab,u));
    return dist(p,c);
}

double distToLineSegment(Point p,Point a,Point b, Point &c){
    Vector ap=toVec(a,p),ab=toVec(a,b);
    double u=dot(ap,ab)/magnitude_sqr(ab);
    if(u<0.0){
        c=Point(a.x,a.y);
        return dist(p,a);
    }
    if(u>1.0){ c=Point(b.x,b.y); return dist(p,b);}
    return distToLine(p,a,b,c);
}

double angle(Point a,Point o,Point b){
    Vector oa=toVec(o,a),ob=toVec(o,b);
    return acos(dot(oa,ob)/sqrt(magnitude_sqr(oa)*magnitude_sqr(ob)));
}

double cross(Vector a,Vector b){
    return a.x*b.y-a.y*b.x;
}

bool ccw(Point p,Point q,Point r){
    return cross(toVec(p,q),toVec(p,r))>=-EPS;
}

bool collinear(Point p,Point q,Point r){
    return fabs(cross(toVec(p,q),toVec(p,r)))<EPS;
}

int insideCircle(Point p, Point center,double r){
    double dx=p.x-center.x,dy=p.y-center.y;
    double dis=hypot(dx,dy);
    return fabs(dis-r)<EPS? 1 : dis<r? 0: 2;
}

double chordLength(double r,double ang){
    return 2*r*sin(ang/2);
}

double sectorArea(double r,double ang){
    double pi=acos(-1.0);
    return (ang/(pi*2))*pi*r*r;
}

double segmentArea(double r,double ang){
    double sArea=sectorArea(r,ang);
    double chordL=chordLength(r,ang);
    double triArea=0.5*chordL*sqrt(r*r-chordL*chordL/4);
    return sArea-triArea;
}

bool circle2PtsRadius(Point p1,Point p2,double r,Point &c){
    double dis2=(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
    double det=r*r/dis2-0.25;

    if(det<0.0) return false;
    double h=sqrt(det);
    c.x=(p1.x+p2.x)*0.5+(p1.y-p2.y)*h;
    c.y=(p1.y+p2.y)*0.5+(p2.x-p1.x)*h;
    return true;
}

bool circleCenter(Point p1,Point p2, Point p3,Point &ctr){
    Point m1=(p1+p2)/2;
    Point m2=(p1+p3)/2;
    if(collinear(p1,p2,p3)) return false;

    Line l1,l2;
    if(fabs(p1.y-p2.y)<EPS){
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

    if(fabs(p1.y-p3.y)<EPS){
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
    if(fabs(r)<EPS) return 0;

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

    Line l1,l2;
    Point m1=Point((p1.x+p2.x)/2,(p1.y+p2.y)/2),m2=Point((p1.x+p3.x)/2,(p1.y+p3.y)/2);
    if(fabs(p1.y-p2.y)<EPS){
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

    if(fabs(p1.y-p3.y)<EPS){
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

    areIntersect(l1,l2,c);
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
        else return false;
    }
    else return false;
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
    return fabs(result)/2.0;
}

bool isConvex(const vector<Point> &points){
    int siz=points.size();
    if(siz<=3) return false;
    bool isLeft=ccw(points[0],points[1],points[2]);

    for(int i=1;i<siz-1;i++){
        if(ccw(points[i],points[i+1],points[(i+2)==siz? 1 : i+2])!=isLeft)
            return false;
    }
    return true;
}

bool inPolygon(Point pt,const vector<Point> &points){
    int siz=points.size();

    if(siz==0) return false;
    double sum=0;
    Point temp;

    for(int i=0;i<siz-1;i++){
        if(ccw(pt,points[i],points[i+1])){
            ///if(distToLineSegment(pt,points[i],points[i+1],temp)<EPS) return true;
            sum+=angle(points[i],pt,points[i+1]);
        }
        else sum-=angle(points[i],pt,points[i+1]);
    }

    return fabs(fabs(sum)-2*PI)<EPS;
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

bool angleCmp(Point a,Point b){
    if(collinear(pivot,a,b)){

        if(abs(pivot.y-a.y)<EPS) return dist(pivot,a)>dist(pivot,b);


        double tempang;
        if(a.x-pivot.x<EPS) tempang=PI-atan2(a.y-pivot.y,abs(a.x-pivot.x));
        else tempang=atan2(a.y-pivot.y,a.x-pivot.x);

        if(abs(tempang-maxang)<EPS) return dist(pivot,a)>dist(pivot,b);

        return dist(pivot,a)<dist(pivot,b);
    }
    double d1x=a.x-pivot.x,d1y=a.y-pivot.y;
    double d2x=b.x-pivot.x,d2y=b.y-pivot.y;
    return (atan2(d1y,d1x)-atan2(d2y,d2x))<0;
}

vector<Point> convexHull(vector<Point> points){
    int j,siz=points.size();

    if(siz<=3){
        if(!(points[0]==points[siz-1])) points.push_back(points[0]);
        return points;
    }

    int p0=0;

    for(int i=1;i<siz;i++){
        if(points[i].y<points[p0].y||(abs(points[i].y-points[p0].y)<EPS&&points[i].x>points[p0].x)){
            p0=i;
        }
    }

    Point temp=points[0];
    points[0]=points[p0];
    points[p0]=temp;

    pivot=points[0];

    for(int i=1;i<siz;i++){

        double tempang;
        if(points[i].x-pivot.x<EPS){
            tempang=PI-atan2(points[i].y-pivot.y,abs(points[i].x-pivot.x));
        }
        else tempang=atan2(points[i].y-pivot.y,points[i].x-pivot.x);

        maxang=max(maxang,tempang);
        minang=min(minang,tempang);
    }

    sort(++points.begin(),points.end(),angleCmp);

    vector<Point> ans;
    ans.push_back(points[siz-1]);
    ans.push_back(points[0]);
    ans.push_back(points[1]);

    int i=2;
    while(i<siz){
        j=(int) ans.size()-1;
        if(ccw(ans[j-1],ans[j],points[i])) ans.push_back(points[i++]);
        else ans.pop_back();
    }
    return ans;
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin>>t;

    for(int cas=1;cas<=t;cas++){
        maxang=0,minang=PI;
        int n,d; scanf("%d",&n);
        vector<Point> pts;
        map<pii,int>myMap;
        for(int i=0;i<n; i++){
            int x,y; scanf("%d %d",&x,&y);
            if(myMap[pii(x,y)]==0) {
                myMap[pii(x,y)]=1;
                pts.pb(Point(x, y));
            }
        }

        cout<<"Case "<<cas<<": "<<fixed<<setprecision(10);
        if(pts.size()<=2){
            cout<<0<<endl;
        }
        else{

            pts=convexHull(pts);

            double minangle=2*PI;

            double ang=angle(pts[pts.size()-2],pts[0],pts[1]);
            minangle=min(minangle,ang);


            for(int i=0;i<pts.size()-2;i++){
                ang=angle(pts[i],pts[i+1],pts[i+2]);
                minangle=min(minangle,ang);
            }

            cout<<minangle*180/PI<<endl;
        }
    }

    return 0;
}
