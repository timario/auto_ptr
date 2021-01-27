#pragma once
#ifndef STRING_PTR_H
#define STRING_PTR_H

#include<string>
#include <cassert>

class string_ptr
{
public:
    typedef std::string element_type;

    explicit
        string_ptr(std::string* p = 0) :
        m_ptr(p)

    {}

    ~string_ptr()
    {
        
        delete m_ptr;
    }

    string_ptr(string_ptr& r) 
    {
        m_ptr = r.m_ptr;
        r.m_ptr = nullptr;
    }
    string_ptr& operator=(string_ptr& r)   
    {
        string_ptr tmp(r.release());
        tmp.swap(*this);
        return *this;

    }

    const std::string& operator*()  const
    {
        return *m_ptr;
    }

    std::string& operator*()
    {
        return *m_ptr;
    }

    const std::string* operator->() const
    {
        return m_ptr;
    }
    std::string* operator->()
    {
        return m_ptr;
    }

    const std::string* get() const
    {
        return m_ptr;
    }
    std::string* get()
    {
        return m_ptr;
    }

    std::string* release()
    {
        element_type* tmp = new std::string;
        *tmp = *this->m_ptr;
        this->~string_ptr();
        return tmp;
    }

private:
    std::string* m_ptr;
    string_ptr swap(string_ptr &r)
    {
        string_ptr tmp;
        tmp.m_ptr = m_ptr;
        m_ptr = r.m_ptr;
        r.m_ptr = tmp.m_ptr;
    }

};

#endif // STRING_PTR_H
