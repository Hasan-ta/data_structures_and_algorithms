#ifndef DYNAMIC_ARRAYS_LIBS_DYNAMICARRAY_HPP
#define DYNAMIC_ARRAYS_LIBS_DYNAMICARRAY_HPP

#include <memory>
template <typename T> class DynamicArray
{
    public:

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
        DynamicArray(const uint32_t& capacity, const T& value=T());

        /**
         * @brief      Number of elements in array
         *
         * @return     Number of elements in array
         */
        uint32_t size() const;

        /**
         * @brief      Get element at index i
         *
         * @param[in]  i     index of element to retrieve 
         *
         * @return     A copy of the element at index i
         */
        virtual T operator[](const uint32_t& i) const;

        /**
         * @brief      Append element to the end of array
         *
         * @param[in]  element  The element
         */
        virtual void append(const T& element);

        uint32_t capacity_ = 8;

    private:

        uint32_t numOfElements_ = 0;



        std::shared_ptr<T> arrayPointer_;

        void resize();
        
};

#include "DynamicArrayImpl.hpp"

#endif