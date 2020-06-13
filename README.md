MSL - The Lasersköld Support Library
=======================================

With goodies like not_null_unique_ptr, starts_with and replace_all

Installation
-------------

Msl is a header only libray and all functions is supposed to be light weight.
Clone the repository to your project and add mls/include to your include paths.




Examples
-------------------------------------------------------

``` c++

#include "msl/range.h"
#include <string>

int main(int argc, char ** argv) {
   using namespace msl;

   // Print numbers 0 to 9
   for (auto i : range(10) ) {
      cout << i << "\n";
   }

   // To start at 2
   for (auto i : range(2, 10) ) {
      cout << i << "\n";
   }

   // Indices of lists
   std::string str = "hello";
   for (auto i : range(str.size()) {
      cout << "character at index " << i << ": " << str.at(i) << "\n";
   }
}

```

``` c++

#include "msl/not_null_unique_ptr"

// Function that takes ownership of pointer
void unique_pointer_sink(msl::not_null_unique_ptr<int> ptr) {
   // This is of course not something you would do with ints normally
   auto owner = std::move(ptr);

   // ... do something with owner that is a unique_ptr
}



int main(int argc, char ** argv) {

}

```
