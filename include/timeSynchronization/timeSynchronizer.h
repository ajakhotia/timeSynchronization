/*
 * Copyright 2019
 * Author: Anurag Jakhotia
 * Email: 5448528+ajakhotia@users.noreply.github.com
 */
#pragma once

namespace timeSynchronization
{

template<typename RemoteClock_, typename HostClock_>
class TimeSynchronizer
{
public:
    using RemoteClock = RemoteClock_;

    using HostClock = HostClock_;

    TimeSynchronizer();

    ~TimeSynchronizer() = default;

    TimeSynchronizer(const TimeSynchronizer&) = delete;

    TimeSynchronizer(TimeSynchronizer&&) = default;

    TimeSynchronizer& operator=(const TimeSynchronizer&) = delete;

    TimeSynchronizer& operator=(TimeSynchronizer&&) = delete;

private:


};
} // End of namespace timeSynchronization.