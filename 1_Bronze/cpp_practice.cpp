#if 0
#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
void swap_value(T &a, T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_value(char *s1, char *s2){
    int len;

    len = (strlen(s1) >= strlen(s2)) ? strlen(s1) : strlen(s2);
    cout << len << endl;
    char * temp = new char[len+1];

    strcpy(temp, s1);
    strcpy(s1,s2);
    strcpy(s2, temp);
    delete[] temp;
}

int main(void){
    int x=10, y= 20;
    swap_value(x,y);
    cout << x << y << endl;

    char s1[100] = "this is a first stringaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char s2[100] = "this is a second string";
    swap_value(s1,s2);
    cout << s1 << "  " <<s2 << endl;
    return 0;
}
#endif

#if 0
#include <iostream>

using namespace std;

template <typename T>
class Box{
    T data; //T는 타입(Type)을 나타낸다.
public:
    Box(){

    }
    void set(T value){
        data = value;
    }
    T get(){
        return data;
    }
};

int main(void){
    Box<int> box;
    box.set(100);
    cout << box.get() << endl;

    Box<double> box1;
    box1.set(3.1412);
    cout << box1.get() << endl;

    return 0;
}
#endif

#if 0
#include <iostream>

using namespace std;

template <typename T1, typename T2>

class Box2{
    T1 first_data;
    T2 second_data;

    public:
        Box2(){}
        T1 get_first();
        T2 get_second();
        void set_first(T1 value);
        void set_second(T2 value);
};

template <typename T1, typename T2>
T1 Box2<T1,T2>::get_first(){
    return first_data;
}

template <typename T1, typename T2>
T2 Box2<T1,T2> ::get_second(){
    return second_data;
}

template<typename T1, typename T2>
void Box2<T1,T2> :: set_first(T1 value){
    first_data = value;
}

template<typename T1, typename T2>
void Box2<T1,T2> :: set_second(T2 value){
    second_data = value;
}

int main(void){
    Box2<int, double> b;
    b.set_first(10);
    b.set_second(3.14);
    cout << "(" << b.get_first() << ")" << endl;
    return 0;
}
#endif

#if 0
#include <iostream>

using namespace std;

class Coord2D
{
protected:
    int x;
    int y;
public:
    Coord2D(int _x, int _y):x(_x),y(_y){}
    ~Coord2D(){
        cout<<"hello"<< endl;
    }
    void showCoord2D();
};

void Coord2D::showCoord2D(){
    cout << x <<" "<< y<<endl;
}

class Coord3D : public Coord2D //puplic도 물려받고 protected도 물려받는
{
private:
    int z;
public:
    Coord3D(int _x, int _y, int _z):Coord2D(_x,_y),z(_z){}
    ~Coord3D(){
        cout<<"hello2"<<endl;
    }
    
    void showCoord3D();
};

void Coord3D:: showCoord3D(){
    showCoord2D();
    cout<<" ," << z << endl;
}

int main(void){
    Coord3D temp(10,20,30);
    temp.showCoord3D();

    return 0;
}
#endif

#if 0
#include <iostream>
#include <string>

using namespace std;

class Car{

public:
    int speed;

    void setSpeed(int s){
        this->speed = s;
    }
    int getspeed(){
        return this->speed;
    }
};

//car 클래스를 상속받아서 다음과 같이 sportcar 클래스를 작성
class SportCar : public Car{

public:
    bool turbo;

    void setTurbo(bool newValue){
        this->turbo = newValue;
    }
    bool getTurbo(){
        return this->turbo;
    }

    void print_current(){
        cout << this->turbo << " "<<this->speed << endl;
    }
};

int main(void){

    SportCar c;
    
    c.setSpeed(60);
    c.setTurbo(true);
    c.setSpeed(100);
    c.setTurbo(false);

    c.print_current();
}
#endif

#include <iostream>

using namespace std;

class PassangerCar{

public:
    int seats;//
    PassangerCar(int seats):seats(seats){}
    void set_seats(int n){
        this->seats = n;
    }
};

class Truck{

public:
    int payload;
    Truck(int payload):payload(payload){}
    void set_payload(int load){
        this->payload = load;
    }
};

class Pickup : public PassangerCar, public Truck{

public:
    int tow_capability;
    Pickup(int seats, int payload, int tow_capability ): PassangerCar(seats),Truck(payload),tow_capability(tow_capability){}
    void print_123(){
        cout << this->seats <<" " << this->payload <<" "<< tow_capability << endl;
    }
    void set_tow(int capa){
        this->tow_capability = capa;
    }
};

int main(){
    Pickup my_car(10,20,30);
    my_car.print_123();
    
    return 0;
}

