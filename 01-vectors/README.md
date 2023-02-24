# vector data structure

`MyVector`

-  `size_t the_size`
-  `size_t the_capacity`
-  `data_type *data`
-  `static const size_t SPARE_CAPACITY = 16`
-  `explicit MyVector(size_t init_size = 0)`
-  `MyVector(const MyVector & rhs)`
-  `MyVector(MyVector && rhs)`
-  `MyVector(const std::vector<data_type> & rhs)`
-  `~MyVector()`
-  `MyVector & operator= (const MyVector & rhs)`
-  `MyVector & operator= (MyVector && rhs)`
-  `void resize(size_t new_size)`
-  `void reserve(size_t new_capacity)`
-  `data_type & operator[] (size_t index)`
-  `
