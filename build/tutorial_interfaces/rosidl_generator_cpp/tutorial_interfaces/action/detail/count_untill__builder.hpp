// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:action/CountUntill.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACES__ACTION__DETAIL__COUNT_UNTILL__BUILDER_HPP_
#define TUTORIAL_INTERFACES__ACTION__DETAIL__COUNT_UNTILL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tutorial_interfaces/action/detail/count_untill__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tutorial_interfaces
{

namespace action
{

namespace builder
{

class Init_CountUntill_Goal_order
{
public:
  Init_CountUntill_Goal_order()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tutorial_interfaces::action::CountUntill_Goal order(::tutorial_interfaces::action::CountUntill_Goal::_order_type arg)
  {
    msg_.order = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntill_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::action::CountUntill_Goal>()
{
  return tutorial_interfaces::action::builder::Init_CountUntill_Goal_order();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace action
{

namespace builder
{

class Init_CountUntill_Result_sequence
{
public:
  Init_CountUntill_Result_sequence()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tutorial_interfaces::action::CountUntill_Result sequence(::tutorial_interfaces::action::CountUntill_Result::_sequence_type arg)
  {
    msg_.sequence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntill_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::action::CountUntill_Result>()
{
  return tutorial_interfaces::action::builder::Init_CountUntill_Result_sequence();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace action
{

namespace builder
{

class Init_CountUntill_Feedback_partial_sequence
{
public:
  Init_CountUntill_Feedback_partial_sequence()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tutorial_interfaces::action::CountUntill_Feedback partial_sequence(::tutorial_interfaces::action::CountUntill_Feedback::_partial_sequence_type arg)
  {
    msg_.partial_sequence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntill_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::action::CountUntill_Feedback>()
{
  return tutorial_interfaces::action::builder::Init_CountUntill_Feedback_partial_sequence();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace action
{

namespace builder
{

class Init_CountUntill_SendGoal_Request_goal
{
public:
  explicit Init_CountUntill_SendGoal_Request_goal(::tutorial_interfaces::action::CountUntill_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::action::CountUntill_SendGoal_Request goal(::tutorial_interfaces::action::CountUntill_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntill_SendGoal_Request msg_;
};

class Init_CountUntill_SendGoal_Request_goal_id
{
public:
  Init_CountUntill_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CountUntill_SendGoal_Request_goal goal_id(::tutorial_interfaces::action::CountUntill_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_CountUntill_SendGoal_Request_goal(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntill_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::action::CountUntill_SendGoal_Request>()
{
  return tutorial_interfaces::action::builder::Init_CountUntill_SendGoal_Request_goal_id();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace action
{

namespace builder
{

class Init_CountUntill_SendGoal_Response_stamp
{
public:
  explicit Init_CountUntill_SendGoal_Response_stamp(::tutorial_interfaces::action::CountUntill_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::action::CountUntill_SendGoal_Response stamp(::tutorial_interfaces::action::CountUntill_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntill_SendGoal_Response msg_;
};

class Init_CountUntill_SendGoal_Response_accepted
{
public:
  Init_CountUntill_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CountUntill_SendGoal_Response_stamp accepted(::tutorial_interfaces::action::CountUntill_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_CountUntill_SendGoal_Response_stamp(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntill_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::action::CountUntill_SendGoal_Response>()
{
  return tutorial_interfaces::action::builder::Init_CountUntill_SendGoal_Response_accepted();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace action
{

namespace builder
{

class Init_CountUntill_GetResult_Request_goal_id
{
public:
  Init_CountUntill_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tutorial_interfaces::action::CountUntill_GetResult_Request goal_id(::tutorial_interfaces::action::CountUntill_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntill_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::action::CountUntill_GetResult_Request>()
{
  return tutorial_interfaces::action::builder::Init_CountUntill_GetResult_Request_goal_id();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace action
{

namespace builder
{

class Init_CountUntill_GetResult_Response_result
{
public:
  explicit Init_CountUntill_GetResult_Response_result(::tutorial_interfaces::action::CountUntill_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::action::CountUntill_GetResult_Response result(::tutorial_interfaces::action::CountUntill_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntill_GetResult_Response msg_;
};

class Init_CountUntill_GetResult_Response_status
{
public:
  Init_CountUntill_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CountUntill_GetResult_Response_result status(::tutorial_interfaces::action::CountUntill_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_CountUntill_GetResult_Response_result(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntill_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::action::CountUntill_GetResult_Response>()
{
  return tutorial_interfaces::action::builder::Init_CountUntill_GetResult_Response_status();
}

}  // namespace tutorial_interfaces


namespace tutorial_interfaces
{

namespace action
{

namespace builder
{

class Init_CountUntill_FeedbackMessage_feedback
{
public:
  explicit Init_CountUntill_FeedbackMessage_feedback(::tutorial_interfaces::action::CountUntill_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::tutorial_interfaces::action::CountUntill_FeedbackMessage feedback(::tutorial_interfaces::action::CountUntill_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntill_FeedbackMessage msg_;
};

class Init_CountUntill_FeedbackMessage_goal_id
{
public:
  Init_CountUntill_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CountUntill_FeedbackMessage_feedback goal_id(::tutorial_interfaces::action::CountUntill_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_CountUntill_FeedbackMessage_feedback(msg_);
  }

private:
  ::tutorial_interfaces::action::CountUntill_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::action::CountUntill_FeedbackMessage>()
{
  return tutorial_interfaces::action::builder::Init_CountUntill_FeedbackMessage_goal_id();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__ACTION__DETAIL__COUNT_UNTILL__BUILDER_HPP_
