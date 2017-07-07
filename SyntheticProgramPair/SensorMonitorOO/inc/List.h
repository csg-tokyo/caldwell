/*
 * List.h
 *
 *  Created on: Mar 27, 2017
 *      Author: Joe
 */

#ifndef LIST_H_
#define LIST_H_

template<typename T> class List {

   public:
      List ();

   public:
      void add (T item);
      void remove (T item);

   public:
      T const& operator[] (uint32_t index) const;
      uint32_t size () const;

   private:
      void ensureCapacity (uint32_t size);

   private:
      T* m_items;
      uint32_t m_size;
      uint32_t m_capacity;

   private:
      static const int DEFAULT_CAPACITY = 8;
};

template <typename T> List<T>::List(): m_items(new T[List<T>::DEFAULT_CAPACITY]), m_size(0), m_capacity(List<T>::DEFAULT_CAPACITY) {

}

template <typename T> void List<T>::add (T item) {
   ensureCapacity(m_size + 1);
   m_items[m_size++] = item;
}

template <typename T> T const& List<T>::operator[] (uint32_t index) const {
   return m_items[index];
}

template <typename T> uint32_t List<T>::size () const {
   return m_size;
}

template <typename T> void List<T>::ensureCapacity (uint32_t size) {
   if (m_capacity >= size)
      return;

   uint32_t newCapacity = m_capacity * 2;
   while (newCapacity < size)
      newCapacity *= 2;

   T* newItems = new T[newCapacity];

   for (int i = 0; i < m_size; ++i)
      newItems[i] = m_items[i];

   delete m_items;
   m_items = newItems;
   m_capacity = newCapacity;
}

#endif /* LIST_H_ */
