/*

MIT License

Copyright (c) 2018 Chris McArthur, prince.chrismc(at)gmail(dot)com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#ifndef __CSTATTIMER_H__
#define __CSTATTIMER_H__

#include <chrono>
#include "Host.h"

class CStatTimer
{
   using TimePoint = decltype( std::chrono::high_resolution_clock::now() );
public:
   CStatTimer() = default;

   void Initialize() const noexcept { /* Does Nothing Meaningful */ }

   TimePoint GetStartTime() const { return m_startTime; }
   void SetStartTime() { m_startTime = GetTimeNow(); }

   TimePoint GetEndTime() const { return m_endTime; };
   void SetEndTime() { m_endTime = GetTimeNow(); }

   uint64 GetMilliSeconds() const { return std::chrono::duration_cast<std::chrono::milliseconds>( m_startTime - m_endTime ).count(); }
   uint64 GetMicroSeconds() const { return std::chrono::duration_cast<std::chrono::microseconds>( m_startTime - m_endTime ).count(); }
   uint64 GetSeconds() const { return std::chrono::duration_cast<std::chrono::seconds>( m_startTime - m_endTime ).count(); }

   static TimePoint GetTimeNow() { return std::chrono::high_resolution_clock::now(); }

private:
   TimePoint m_startTime;
   TimePoint m_endTime;
};

#endif // __CSTATTIMER_H__