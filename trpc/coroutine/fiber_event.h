//
//
// Copyright (C) 2019 THL A29 Limited, a Tencent company. All rights reserved.
// Flare is licensed under the BSD 3-Clause License.
// The source codes in this file based on
// https://github.com/Tencent/flare/blob/master/flare/fiber/detail/waitable.h.
// This source file may have been modified by THL A29 Limited, and licensed under the BSD 3-Clause License.
//
//

#pragma once

#include "trpc/runtime/threadmodel/fiber/detail/waitable.h"

namespace trpc {

/// @brief Event for fiber. 
class FiberEvent {
 public:
  /// @brief Wait until `Set()` is called.
  ///        If `Set()` is called before `Wait()`, this method returns immediately.
  /// @note  This method only uses in fiber runtime.
  void Wait() { event_.Wait(); }

  /// @brief Wake up fibers blockings on `Wait()`.
  /// @note  You can call this method outside of fiber runtime.
  void Set() { event_.Set(); }

 private:
  trpc::fiber::detail::Event event_;
};

}  // namespace trpc
