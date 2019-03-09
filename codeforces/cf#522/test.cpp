#include<iostream>
using namespace std;
#include<exception>

template<class T>
class SeqList{
	protected:
		T *element;
		int length;
		int n;

	private:
		void init(T values[],int n);

	public:
		SeqList(int length=32);
		SeqList(int length,T x);
		SeqList(T values[],int n);
		~SeqList();

		bool empty();
		int count();
		T& operator[](int i);
		friend ostream& operator<<<>(ostream&,SeqList<T>&);
		void printPrevious();
		void insert(int i,T x);
		virtual void insert(T x);
		T remove(int i);
		void removeAll();
		virtual int search(T key,int start=0);
		virtual void removeFirst(T key);

		SeqList(SeqList<T> &list);
		SeqList<T>& operator=(SeqList<T> &list);
		bool operator==(SeqList<T> &list);
		bool operator!=(SeqList<T> &list);
		void operator+=(SeqList<T> &list);
		SeqList<T> operator+(SeqList<T> &list);
};

template<class T>
SeqList<T>::SeqList(int length){
	this->element=new T[length];
	this->length=length;
	this->n=0;
}
template<class T>
SeqList<T>::SeqList(int length,T x){
	this->element=new T[length];
	this->length=this->n=length;
	for(int i=0;i<this->n;i++)this->element[i]=x;
}
template<class T>
SeqList<T>::SeqList(T values[],int n){
	this->init(values,n);
}
template<class T>
void SeqList<T>::init(T values[],int n){
	this->length=n*2;
	this->element=new T[this->length];
	this->n=n;
	for(int i=0;i<n;i++)this->element[i]=values[i];
}
template<class T>
SeqList<T>::~SeqList(){
	delete []this->element;
}
template<class T>
bool SeqList<T>::empty(){
	return this->n==0;	
}
template<class T>
int SeqList<T>::count(){
	return this->n;
}
template<class T>
T& SeqList<T>::operator[](int i){
	if(i>=0&&i<this->n)return this->element[i];
	throw out_of_range("error");
}
template<class T>
ostream& operator<<<>(ostream& out,SeqList<T>& list){
	out<<'(';
	if(list.n>0)out<<list.element[0];
	for(int i=0;i<list.n;i++)out<<','<<list.element[i];
	out<<')'<<endl;
	return out;
}
template<class T>
void SeqList<T>::insert(int i,T x){
	if(i<0)i=0;
	if(i>this->n)i=this->n;
	T *temp=this->element;
	if(this->n==this->length){
		this->length*=2;
		this->element=new T[this->length];
		for(int j=0;j<i;j++)this->element[j]=temp[j];
	}
	for(int j=this->n-1;j>=i;j--)this->element[j+1]=temp[j];
	if(temp!=this->element)delete[] temp;
	this->element[i]=x;
	this->n++;
}
template<class T>
void SeqList<T>::insert(T x){
	insert(this->n,x);
}
template<class T>
T SeqList<T>::remove(int i){
	if(this->n>0&&i>=0&&i<n){
		T old=this->element[i];
		for(int j=i;j<this->n-1;j++)this->element[j]=this->element[j+1];
		this->n--;
		return old;
	}
	throw out_of_range("error");
}
template<class T>
void SeqList<T>::removeAll(){
	this->n=0;
}
template<class T>
int SeqList<T>::search(T key,int start){
	for(int i=start;i<this->n;i++)if(this->element[i]==key)return i;
	return -1;
}
