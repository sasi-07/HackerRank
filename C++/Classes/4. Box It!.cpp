
//Implement the class Box  

//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box{
    private:
        int length, breadth, height;

    public:
        Box(){
            length = breadth = height = 0;
        }
        Box(int l, int b, int h){
            length = l;
            breadth = b;
            height = h;
        }
        Box(Box &B){
            length = B.length;
            breadth = B.breadth;
            height = B.height;
        }
        int getLength() {
            return length;
        }
        int getBreadth() {
            return breadth;
        }
        int getHeight() {
            return height;
        }
        long long CalculateVolume(){
            long long volume = (long long)length * breadth * height;
            return volume;
        }
        bool operator<(Box &B) {
            if ((length < B.length) || (breadth < B.breadth && length == B.length) || (height < B.height && length == B.length && breadth == B.breadth ))
                return true;
            return false;
        }
};
ostream& operator<<(ostream &out, Box &B) {
  out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
  return out;
};

