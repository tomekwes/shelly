#include "../src/prompt.h" // Assuming you have some logic here
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <sstream>

struct PromptFixture : public ::testing::Test {
  shelly::prompt p;
  std::stringstream test_input_stream;
  std::stringstream test_output_stream;

  void SetUp() {
    p.setStdIn(test_input_stream);
    p.setStdOut(test_output_stream);
  }
};

TEST_F(PromptFixture, CollectingTokens) {

  using DataAndExpected = std::pair<std::string, std::vector<std::string>>;

  std::vector<DataAndExpected> data_set{
      {"hello", {"hello"}},
      {" hello ", {"hello"}},
      {"    hello    ", {"hello"}},
      {"git commit -m \"commit data\"", {"git", "commit", "-m", "commit data"}},
      {"hello to you", {"hello", "to", "you"}}};

  std::for_each(data_set.begin(), data_set.end(), [&](auto data_entry) {
    test_input_stream.clear();
    test_input_stream << data_entry.first;
    auto data = p.readLine();
    EXPECT_THAT(data_entry.second, ::testing::ContainerEq(data));
  });
}
