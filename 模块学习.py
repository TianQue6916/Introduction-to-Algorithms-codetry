"""
时间模块 - 提供各种与时间相关的函数和常量
包含时间转换、时间获取、时间设置等功能
"""
import sys
from _typeshed import structseq
from typing import Any, Final, Literal, Protocol, final, type_check_only
from typing_extensions import TypeAlias

# 定义时间元组的类型别名，包含9个整数的元组
_TimeTuple: TypeAlias = tuple[int, int, int, int, int, int, int, int, int]



# 时区相关变量
altzone: int  # 与本地时区的UTC偏移量（以秒为单位，考虑夏令时）
daylight: int  # 是否使用夏令时的标志
timezone: int  # 与本地时区的UTC偏移量（以秒为单位，不考虑夏令时）
tzname: tuple[str, str]  # 包含本地时区名称的元组

# Linux平台特定的时钟常量
if sys.platform == "linux":
    CLOCK_BOOTTIME: int  # 系统启动以来的时间，包括休眠时间
# 非Windows、非Linux、非Darwin平台特定的时钟常量
if sys.platform != "linux" and sys.platform != "win32" and sys.platform != "darwin":
    CLOCK_PROF: int  # FreeBSD, NetBSD, OpenBSD - 进程执行时间
    CLOCK_UPTIME: int  # FreeBSD, OpenBSD - 系统启动后的时间（不包括休眠时间）

# 非Windows平台特定的时钟常量
if sys.platform != "win32":
    CLOCK_MONOTONIC: int  # 不受系统时间调整影响的单调时钟
    CLOCK_MONOTONIC_RAW: int  # 更精确的单调时钟，不受NTP调整影响
    CLOCK_PROCESS_CPUTIME_ID: int  # 当前进程的CPU时间
    CLOCK_REALTIME: int  # 实时时钟，受系统时间调整影响
    CLOCK_THREAD_CPUTIME_ID: int  # 当前线程的CPU时间
    # 非Linux、非Darwin平台的特定时钟常量
    if sys.platform != "linux" and sys.platform != "darwin":
        CLOCK_HIGHRES: int  # Solaris only - 高分辨率时钟

# Darwin平台特定的时钟常量
if sys.platform == "darwin":
    CLOCK_UPTIME_RAW: int  # 不受NTP调整影响的系统运行时间
    if sys.version_info >= (3, 13):
        CLOCK_UPTIME_RAW_APPROX: int  # 近似的系统运行时间
        CLOCK_MONOTONIC_RAW_APPROX: int  # 近似的单调时钟时间

# Linux平台特定的时钟常量
if sys.platform == "linux":
    CLOCK_TAI: int  # 国际原子时（TAI）时钟

# Constructor takes an iterable of any type, of length between 9 and 11 elements.
# However, it always *behaves* like a tuple of 9 elements,
# even if an iterable with length >9 is passed.
# https://github.com/python/typeshed/pull/6560#discussion_r767162532
@final
class struct_time(structseq[Any | int], _TimeTuple):
    if sys.version_info >= (3, 10):
        __match_args__: Final = ("tm_year", "tm_mon", "tm_mday", "tm_hour", "tm_min", "tm_sec", "tm_wday", "tm_yday", "tm_isdst")

    @property
    def tm_year(self) -> int: ...
    @property
    def tm_mon(self) -> int: ...
    @property
    def tm_mday(self) -> int: ...
    @property
    def tm_hour(self) -> int: ...
    @property
    def tm_min(self) -> int: ...
    @property
    def tm_sec(self) -> int: ...
    @property
    def tm_wday(self) -> int: ...
    @property
    def tm_yday(self) -> int: ...
    @property
    def tm_isdst(self) -> int: ...
    # These final two properties only exist if a 10- or 11-item sequence was passed to the constructor.
    @property
    def tm_zone(self) -> str: ...
    @property
    def tm_gmtoff(self) -> int: ...

def asctime(time_tuple: _TimeTuple | struct_time = ..., /) -> str: ...
def ctime(seconds: float | None = None, /) -> str: ...
def gmtime(seconds: float | None = None, /) -> struct_time: ...
def localtime(seconds: float | None = None, /) -> struct_time: ...
def mktime(time_tuple: _TimeTuple | struct_time, /) -> float: ...
def sleep(seconds: float, /) -> None: ...
def strftime(format: str, time_tuple: _TimeTuple | struct_time = ..., /) -> str: ...
def strptime(data_string: str, format: str = "%a %b %d %H:%M:%S %Y", /) -> struct_time: ...
def time() -> float: ...

if sys.platform != "win32":
    def tzset() -> None: ...  # Unix only

@type_check_only
class _ClockInfo(Protocol):
    adjustable: bool
    implementation: str
    monotonic: bool
    resolution: float

def get_clock_info(name: Literal["monotonic", "perf_counter", "process_time", "time", "thread_time"], /) -> _ClockInfo: ...
def monotonic() -> float: ...
def perf_counter() -> float: ...
def process_time() -> float: ...

if sys.platform != "win32":
    def clock_getres(clk_id: int, /) -> float: ...  # Unix only
    def clock_gettime(clk_id: int, /) -> float: ...  # Unix only
    def clock_settime(clk_id: int, time: float, /) -> None: ...  # Unix only

if sys.platform != "win32":
    def clock_gettime_ns(clk_id: int, /) -> int: ...
    def clock_settime_ns(clock_id: int, time: int, /) -> int: ...

if sys.platform == "linux":
    def pthread_getcpuclockid(thread_id: int, /) -> int: ...

def monotonic_ns() -> int: ...
def perf_counter_ns() -> int: ...
def process_time_ns() -> int: ...
def time_ns() -> int: ...
def thread_time() -> float: ...
def thread_time_ns() -> int: ...

from 我的实验 import plus as p
from 模块学习2 import plus as p

a=p(1, 2)
print (a)

if __name__ == "__main__":
    # 在这里添加主程序代码
    pass

