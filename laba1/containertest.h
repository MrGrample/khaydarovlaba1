#ifndef CONTAINERTEST_H
#define CONTAINERTEST_H

#include <utility>
#include <experimental/type_traits>
#include <iostream>

namespace _m_ {
// add element
template<class T, typename E> using pushBack = decltype(std::declval<T&>().pushBack(std::declval<const E&>()));
template<class T, typename E> using push_back = decltype(std::declval<T&>().push_back(std::declval<const E&>()));
template<class T, typename E> using add_element = decltype(std::declval<T&>().add_element(std::declval<const E&>()));

// equals
template<class T> using operatorEquals = decltype(std::declval<T&>().operator==(std::declval<const T&>()));
template<class T> using equals = decltype(std::declval<T&>().equals(std::declval<const T&>()));
template<class T> using isEqual = decltype(std::declval<T&>().isEqual(std::declval<const T&>()));
template<class T> using is_equal = decltype(std::declval<T&>().is_equal(std::declval<const T&>()));
}

template <class Expected, template<class...> class Op, class... Args>
using has = std::experimental::is_detected_exact<Expected, Op, Args...>;

template<typename T, typename E, typename D> class ContainerTest {
public:
    static bool areEqual(const T& container1_, const T& container2_) {
        if constexpr(has<bool, _m_::operatorEquals, T>()) {
            return container1_ == container2_;
        } else if constexpr(has<void, _m_::equals, T>()) {
            return container1_.equals(container2_);
        } else if constexpr(has<void, _m_::isEqual, T>()) {
            return container1_.equals(container2_);
        } else if constexpr(has<void, _m_::is_equal, T>()) {
            return container1_.is_equal(container2_);
        }
        static_assert(!std::is_same<T, T>::value, "");
        return false;
    }
    static void addElement(T& container_, const E& element_) {
        if constexpr(has<void, _m_::pushBack, T, E>()) {
            container_.pushBack(element_);
        } else if constexpr(has<void, _m_::push_back, T, E>()) {
            container_.push_back(element_);
        } else if constexpr(has<void, _m_::add_element, T, E>()) {
            container_.add_element(element_);
        } else {
            static_assert(!std::is_same<T, T>::value, "");
        }
    }
    static E createElement() {
        return E();
    }
    static E createElementI(size_t i_) {
        return E(i_);
    }
    static E& getFirst(T& container_) {
        return container_.front();
    }
    static bool copyConstructorTest() {
        T collection1;
        for (size_t i = 0; i < 1000; ++i) {
            D::addElement(collection1, D::createElementI(i));
        }
        T collection2(collection1);
        if (!D::areEqual(collection1, collection2)) {
            std::cout << "COPY CONSTRUCTOR TEST FAILED\n";
            return false;
        }
        D::getFirst(collection2) = D::createElementI(1000);
        if (D::areEqual(collection1, collection2)) {
            std::cout << "COPY CONSTRUCTOR TEST FAILED\n";
            return false;
        }
        T collection3(collection1);
        D::addElement(collection3, D::createElement());
        if (D::areEqual(collection1, collection3)) {
            std::cout << "COPY CONSTRUCTOR TEST FAILED\n";
            return false;
        }
        std::cout << "COPY CONSTRUCTOR TEST PASSED\n";
        return true;
    }
    static bool memoryLeakTest() {
        for (size_t i = 0; i < 500000; ++i) {
            T collection;
            for (size_t j = 0; j < 10000; ++j) {
                try {
                    D::addElement(collection, D::createElement());
                } catch (std::bad_alloc& e) {
                    std::cout << "MEMORY LEAK TEST FAILED\n";
                    return false;
                }
            }
        }
        std::cout << "MEMORY LEAK TEST PASSED\n";
        return true;
    }
};

#endif // CONTAINERTEST_H
