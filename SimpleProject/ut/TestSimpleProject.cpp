#include "SimpleProject.hpp"

#include "Message.hpp"

#include <gtest/gtest.h>

#include "mocks/MockScheduler.hpp"

using namespace ::testing;

namespace project
{

class TestSimpleProject : public Test
{
public:

    void configureSUT(const std::string testCommand)
    {
        sut = std::make_unique<SimpleProject>(mockScheduler, testCommand);
    }

    StrictMock<MockScheduler> mockScheduler;
    std::unique_ptr<SimpleProject> sut = nullptr;
};

TEST_F(TestSimpleProject, emptyCommandThrowsException)
{
    EXPECT_THROW(configureSUT(""), CommandError);
}

TEST_F(TestSimpleProject, wrongCommandThrowsException)
{
    EXPECT_THROW(configureSUT("Hello World"), CommandError);
}

TEST_F(TestSimpleProject, correctCommandSendInd)
{
    EXPECT_CALL(mockScheduler, send_test(_));
    configureSUT("Run HelloWorldInd");
}

} // namespace project
