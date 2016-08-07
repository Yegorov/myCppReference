.. My Cpp Reference documentation master file, created by
   sphinx-quickstart on Sun Jul 24 15:20:56 2016.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to My Cpp Reference's documentation!
============================================

Contents:

.. toctree::
   :maxdepth: 2


Базовые части кода на C/C++
---------------------------

Hello world
~~~~~~~~~~~

Код, который выводит сообщение в поток вывода на C

.. code-block:: c
    :linenos:
    
    #include <stdio.h>
    
    int main(int argc, char** argv)
    {
        printf("Hello world\n");
        getch();
        return 0;
    }
    
Скомпилировать данный код (если сохранить его в файле :file:`hello.c`) 
можно командой: 

:command:`gcc hello.c -o hello`
   
Код, который выводит сообщение в поток вывода на C++

.. code-block:: c++
    :linenos:
    
    #include <iostream>
    
    int main(int argc, char** argv)
    {
        std::cout << "Hello world" << std::endl;
        std::cin.get();
        return 0;
    }

Скомпилировать данный код (если сохранить его в файле :file:`hello.cpp`) 
можно командой: 

:command:`g++ hello.cpp -o hello`
    
.. note::

   В C++ при подключении стандартных C-заголовков, 
   например ``#include <stdio.h>`` предпочтительней использовать
   ``#include <cstdio>``, ``#include <cstring>``

Определения класса
~~~~~~~~~~~~~~~~~~

.. code-block:: c++
    
    class class_name 
    {
    private:
        int* pint_value;
        ...
    public:
        int* get_pvalue()
        {
            return pint_value;
        }
    };

    
.. |nbsp| unicode:: 0xA0 
   :trim:

Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`

