# Copyright 2020 The Magma Authors.
# This source code is licensed under the BSD-style license found in the
# LICENSE file in the root directory of this source tree.
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.7.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_BUILD_TYPE Debug)

project(ModifiedMainAsn)
file(GLOB modified_main_asn_SRC
     "*.h"
     "*.c"
     "*.cpp"
)
add_library(LIB_BSTR
        bstrlib.c
        )
target_include_directories(LIB_BSTR PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR})
add_definitions(-DASN_DISABLE_OER_SUPPORT=1)
add_executable(modified_main_asn ${modified_main_asn_SRC})
target_link_libraries(modified_main_asn LIB_BSTR)
