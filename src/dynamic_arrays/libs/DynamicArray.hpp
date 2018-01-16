#ifndef DYNAMIC_ARRAYS_LIBS_DYNAMICARRAY_HPP
#define DYNAMIC_ARRAYS_LIBS_DYNAMICARRAY_HPP

#include <memory>
template <typename T> class DynamicArray
{
    public:
        typedef T* iterator;
        typedef const T* const_iterator;

        /**
         * @brief      Default Constructor
         */
        DynamicArray();

		/**
		 * @brief      { function_description }
		 *
		 * @param[in]  capacity_  The capacity
		 */
		DynamicArray(const uint32_t& capacity_);

        /**
         * @brief      { function_description }
         *
         * @param[in]  capacity	pre-allocated cpacity of the array
         * @param[in]  value  value to which all elements are initialized
         */
        DynamicArray(const uint32_t& capacity, const T& value);

        /**
         * @brief      Number of elements in array
         *
         * @return     Number of elements in array
         */
        uint32_t size() const;

        /**
         * @brief      Capacity of the array
         *
         * @return     number of allocated memory elements
         */
        uint32_t capacity() const;

        /**
         * @brief      get a reference to the element at index i
         *
         * @param[in]  i     element index
         *
         * @return     reference to the required element
         */
        const T& operator[](const uint32_t& i) const;
        T& operator[](const uint32_t& i);

        /**
         * @brief      Append element to the end of array
         *
         * @param[in]  element  The element
         */
        virtual void append(const T& element);

        /**
         * @brief      pop the last element in the array
         *
         * @return     copy of the last element of the array
         */
        virtual T pop();

        /**
         * @brief      get pointer to first element
         *
         * @return     shared pointer to first element in the array
         */
        const_iterator begin() const;
        iterator begin();

        /**
         * @brief      get a pointer to last element in array
         *
         * @return     shared pointer to last element in the array
         */
        const_iterator end() const;
        iterator end();

    private:

        uint32_t numOfElements_ = 0;

        uint32_t capacity_ = 1;

        std::shared_ptr<T> arrayPointer_;

        void resize();
};

#include "DynamicArrayImpl.hpp"

#endif