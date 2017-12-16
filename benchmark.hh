#ifndef RNICHOLL_BENCHMARK_HH
#define RNICHOLL_BENCHMARK_HH

#include <chrono>
#include <iostream>
#include <string>
#include <atomic>

namespace rnicholl
{
  void benchmark(std::ostream & os, std::string str, std::function<void()> func)
  {
    using namespace std;
    using namespace std::chrono;
    std::chrono::high_resolution_clock::time_point start =
      std::chrono::high_resolution_clock::now();
    high_resolution_clock::time_point end;
    
    size_t s;
    s = 0;
    do
      {

	func();
	s ++;
	end = high_resolution_clock::now();
	std::atomic_signal_fence(std::memory_order::memory_order_seq_cst);
      }
    while ( end - start < chrono::seconds(30) );

    double ct = s;

    os << str << ": " << s << endl;
  }
}

#endif
