#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<random>
using namespace std;

class Wlan;

class Point{
    private:
        static Point origin;
	    double x ;
        double y ;
        double z ; 
    public:
        Point(const double ,const double ,const double);
        Point(const Point &);
        double distance (const Point = origin) const;
	    double distance (const Point* = &origin) const;
	    friend class Wlan;
        void randomize();
};

class Wlan{
    private:
        double range;
    public:
        Point *coordinate;
        string uuid;
		Wlan(Point* , string , double );
        bool inrange(const Wlan*) const;
        void info() const;
        void neighbor_info(const Wlan *n) const;
        void change_location(Point *a);
        void change_location();
};

struct inrange{
	int home_index;
	int neighbor_index;
};

vector<Wlan*> devices;
vector<inrange> inrange_v1,inrange_v2;

default_random_engine gen;
uniform_real_distribution<double> range_distrib(0,25);
uniform_real_distribution<double> xy_coordinate_distrib(-50,50);
uniform_real_distribution<double> z_coordinate_distrib(-2,2);

int main(){
    string id = "tp-1000";
    double r;
    gen.seed(time(0));

    for(int i=0;i<10;i++){
        id[6]='0'+i;
        r = range_distrib(gen);
		Point *loc = new Point(0.0,0.0,0.0);
        loc->randomize();
		Wlan *dev = new Wlan(loc,id,r);
        devices.push_back(dev);
    }

    cout<<"initialised devices";
    for(int i=0;i<10;i++){
        devices[i]->info();
    }
    
    
    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            if(devices[i]->inrange(devices[j])){
                inrange_v1.push_back({i,j});
            }
        }
    }

    cout<<"\n\nin range devices";
    for(int i=0;i<inrange_v1.size();i++){
        devices.at(inrange_v1[i].home_index)->neighbor_info(devices.at(inrange_v1[i].neighbor_index));
    }
    
    cout<<"\n\nnew location of devices";
    for(int i=0;i<devices.size();i++){
		devices[i]->change_location();
    }
    
	for(int i=0;i<devices.size();i++){
        devices[i]->info();
    }


    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            if(devices[i]->inrange(devices[j])){
                inrange_v2.push_back({i,j});
            }
        }
    }

    cout<<"\n\nnew range devices";
    for(int i=0;i<inrange_v2.size();i++){
        devices.at(inrange_v2[i].home_index)->neighbor_info(devices.at(inrange_v2[i].neighbor_index));
    }
    
cout<<endl;	
    for(int i=0;i<devices.size();i++){
    	delete devices[i]->coordinate;
		delete devices[i];
    }
}

Point::Point(const Point &a){
    x=a.x;
    y=a.y;
    z=a.z;
}
Point::Point(const double a,const double b,const double c):x{a},y{b},z{c}{}
Point Point::origin(0.0,0.0,0.0);
double Point::distance(const Point p2) const{
double dist = sqrt(pow(x-p2.x,2)+pow(y-p2.y,2)+pow(z-p2.z,2));
return dist;
}
double Point::distance(const Point *p2) const{
double dist = sqrt(pow(x-p2->x,2)+pow(y-p2->y,2)+pow(z-p2->z,2));
return dist;
}
void Point::randomize(){
    x = xy_coordinate_distrib(gen);
    y = xy_coordinate_distrib(gen);
    z = z_coordinate_distrib(gen);
}

Wlan::Wlan(Point* a, string id, double r){coordinate=a;uuid=id;range=r;}
bool Wlan::inrange(const Wlan *neighbor)const{
    double distance = coordinate->distance(neighbor->coordinate);
    if(distance<=range&&distance<=neighbor->range){
        return true;
    }
    return false;
}
void Wlan::info() const{
    cout<<endl<<uuid<<" at ("<<coordinate->x<<","<<coordinate->y<<","<<coordinate->z<<")"<<" with range : "<<range;
}
void Wlan::neighbor_info(const Wlan *n) const{
    cout<<endl<<uuid<<" neighbor with "<<n->uuid;
}
void Wlan::change_location(Point *a){
    coordinate=a;
}
void Wlan::change_location(){
    coordinate->randomize();
}