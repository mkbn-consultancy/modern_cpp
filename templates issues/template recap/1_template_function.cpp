//-------- MKBN Training and Consultancy --------//
//--------------- miri@mkbn.co.il ---------------//
template <class T> 
inline T MyMax(const T& t1, const T& t2) 
{ 
return (t1 < t2) ? t2 : t1; 
} 

int main() 
{ 
	int highest = MyMax(5,10); 
	char c = MyMax<char>('a', 'z'); 

	vector<int> v = {1,2,3,4};
}
