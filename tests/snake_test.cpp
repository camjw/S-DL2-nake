#include <vector>
#include "snake_test.h"

using ::testing::AtLeast;
using ::testing::ElementsAre;

SnakeTest::SnakeTest() : mock_window(), subject(mock_window, 10, 10, 10, 10, 10, 10, 10) {
};

// TEST_F(SnakeTest, LocationTest)
// {
//   EXPECT_THAT(subject.getLocation(), ElementsAre(0, 10));
// }
