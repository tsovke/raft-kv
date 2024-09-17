#pragma once

#include "data/raft.pb.h"
#include <mutex>
#include <string>
#include <vector>

// struct Log {
//   int l_term;
//   int l_index;
//   std::string command;
// };

enum State {
  Follower,
  Leader,
  Candidate,
};

class Server {
  std::mutex m_mutex;

  int m_id;
  int m_heartbeat;
  int m_voteCount;

  int m_term;
  State m_state;
  int m_votedFor;
  // std::vector<Log> m_log;
  raft::Log m_log;

  int m_lastApplied;
  int m_commitIndex;
  std::vector<int> m_nextIndexVec;
  std::vector<int> m_matchIndexVec;

  void Update();
  void Election();
  void ToLeader();
  void ToCandidate();
  void ToFollower();

  raft::AppendEntriesArgs _appendArgs;
  raft::AppendEntriesReply _appendReply;
  raft::VoteArgs _voteArgs;
  raft::VoteReply _voteReply;

public:
  Server() = delete;
  Server(int id);
  ~Server() = default;

  // void RequestAppendEntries(int term, int leaderId, int prevLogIndex,
  //                           std::vector<Log> &entries, int leaderCommit);
  void RequestAppendEntries(raft::AppendEntriesArgs &_args);
  void ReplyAppendEntries(raft::AppendEntriesReply &_reply);
  // void RequestVote(int term, int candidateId, int lastLogIndex,
  //                  int lastLogTerm);
  void RequestVote(raft::VoteArgs &_args);
  void ReplyVote(raft::VoteReply &_reply);

  void Start();
};
