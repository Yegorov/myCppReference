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

Код, который выводит сообщение в поток вывода на C

.. code-block:: c
    :linenos:
    
    #include <stdio.h>
    
    int main(int argc, char** argv)
    {
        printf("Hello world\n");
        return 0;
    }
    
Код, который выводит сообщение в поток вывода на C++

.. code-block:: c++
    :linenos:
    
    #include <iostream>
    
    int main(int argc, char** argv)
    {
        std::cout << "Hello world" << std::endl;
        return 0;
    }
    
    
Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`

