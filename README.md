# cpp_smartpointer
In modern C++ programming, the Standard Library includes smart pointers, which are used to help ensure that programs are free of memory and resource leaks and are exception-safe.

Smart pointers are defined in the std namespace in the <memory> header file. 
They are crucial to the RAII or Resource Acquisition Is Initialization programming idiom. 
  
Unlike managed languages like python, C++ doesn't have automatic garbage collection. its an internal process that releases heap memory and other resources as a program runs. A C++ program is responsible for returning all acquired resources to the operating system. Failure to release an unused resource is called a leak. Leaked resources are unavailable to other programs until the process exits. 

Modern C++ avoids using heap memory as much as possible by declaring objects on the stack.When a resource is too large for the stack, then it should be owned by an object. As the object gets initialized, it acquires the resource it owns. The object is then responsible for releasing the resource in its destructor. The owning object itself is declared on the stack. The principle that objects own resources is also known as "resource acquisition is initialization," or RAII.

**difference between a raw pointer and smart pointer**
   ```
   void RawPointerExample(){
        // Using a raw pointer -- not recommended.
        Movie* infinitywar = new Movie("Marvel",2019);

        // Use infinitywar...

        // Don't forget to delete!
        delete infinitywar;
    }


void SmartPointerExample(){
        // Declare a smart pointer on stack and pass it the raw pointer.
        std::unique_ptr<Movie> infinitywar{new Movie{"Marvel",2019}};
        
                                 or
       
        std::unique_ptr<Movie> infinitywar = make_unique<Movie>("Marvel", 2019); // from c++14

        // Use infinitywar...
        int total_duration = infinitywar->length;
        
    } // infinitywar is deleted automatically here.

   ```
As shown above, a smart pointer is a class template that you declare on the stack, and initialize by using a raw pointer that points to a heap-allocated object. After the smart pointer is initialized, it owns the raw pointer. This means that the smart pointer is responsible for deleting the memory that the raw pointer specifies. The smart pointer destructor contains the call to delete, and because the smart pointer is declared on the stack, its destructor is invoked when the smart pointer goes out of scope, even if an exception is thrown somewhere further up the stack.

**Types of smart pointers**

unique_ptr
Allows exactly one owner of the underlying pointer. Can be moved to a new owner, but not copied or shared. 

shared_ptr
Reference-counted smart pointer. Use when you want to assign one raw pointer to multiple owners, for example, when you return a copy of a pointer from a container but want to keep the original. The raw pointer is not deleted until all shared_ptr owners have gone out of scope or have otherwise given up ownership.

weak_ptr
Special-case smart pointer for use in conjunction with shared_ptr. A weak_ptr provides access to an object that is owned by one or more shared_ptr instances, but does not participate in reference counting. Use when you want to observe an object, but do not require it to remain alive. 
