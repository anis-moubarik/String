#ifndef STRING_H
#define STRING_H
#ifdef NDEBUG
	#define myAssert(x) __myAssert(true)
#else
	#define myAssert(x) __myAssert(x)
#endif

class String{
public:
	String();
	String(const char * const);
	String(String const&);
	~String();

	//iterators
	template <typename T>
	class iterator
	{
	public:
		typedef iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef std::forward_iterator_tag iterator_category;
		typedef char difference_type;
		iterator(pointer ptr) : ptr_(ptr) { }
		self_type operator++() { self_type i = *this; ptr_++; return i; }
		self_type operator++(int s) {ptr_++; return *this; }
		reference operator*() {return *ptr_; }
		pointer operator ->() {return ptr_;}
		bool operator==(const self_type& rhs) {return ptr_ == rhs.ptr_; }
		bool operator!=(const self_type& rhs) {return ptr_ != rhs.ptr_; }
	private:
		pointer ptr_;
	};

	template <typename T>
	class const_iterator
	{
	public:
		typedef const_iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef char difference_type;
		typedef std::forward_iterator_tag iterator_category;
		const_iterator(pointer ptr) : ptr_(ptr){}
		self_type operator++() {self_type i = *this; ptr_++; return i; }
		self_type operator++(int s) { ptr_++; return *this; }
		const reference operator* () {return *ptr_; }
		const pointer operator->(){return ptr_;}
		bool operator==(const self_type& rhs) { return ptr_ == rhs.ptr_; }
		bool operator!=(const self_type& rhs) { return ptr_ != rhs.ptr_; }
	private:
		pointer ptr_;
	};

	iterator<char> begin() { return iterator<char>(string); }
	iterator<char> end() {return iterator<char>(string + length); }
	const_iterator<char> begin() const { return const_iterator<char>(string); }
	const_iterator<char> end() const { return const_iterator<char>(string + length); }

	//overloads
	String operator +(const String &);
	String & operator = (const String &);
	friend std::ostream& operator << (std::ostream& output, const String &);
	char & operator[] (unsigned int index);
	char operator[] (unsigned int index) const;

	unsigned int strlength() const {return length;}; 
	void push_back(char c);
	char pop_back();
	void insert(char c);
	void erase(int i);
	void swap(String &);
private:
	char * string;
	void check() const;
	unsigned int length;
	static void __myAssert(bool passed);
};

#endif // !STRING_H
