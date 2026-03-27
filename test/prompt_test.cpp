#include <gtest/gtest.h>
#include "../src/prompt.h" // Assuming you have some logic here

struct PromptFixture : public::testing::Test{
    shelly::prompt p;

    void SetUp(){}
};


TEST_F(PromptFixture, CollectingTokens) {

    ASSERT_EQ(1, 1);


}
