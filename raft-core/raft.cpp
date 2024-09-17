#include "raft.h"
#include <chrono>
#include <mutex>
#include <random>
#include <thread>
#include <vector>

Server::Server(int id)
    : m_id(id), m_heartbeat(0), m_voteCount(0), m_term(0),
      m_state(State::Follower), m_votedFor(0), m_log(), m_lastApplied(0),
      m_commitIndex(0), m_nextIndexVec(), m_matchIndexVec() {}

void Server::Update() {
  while (true) {
    // 广播时间或心跳时间
    std::this_thread::sleep_for(std::chrono::milliseconds(20));

    std::unique_lock<std::mutex> _(m_mutex);
    switch (m_state) {
    case Leader:
      // Leader同步日志或心跳
      {
        
      }
    case Candidate:
      // Candidate拉票
    case Follower:
      //异步选举超时计时，变成Candidate
      
      //复制Leader发过来的日志
    default:
    return;
    }
  }
};
void Server::Election(){
  // 任期+1,自投1票
  //拉票
};
void Server::RequestVote(int term, int candidateId, int lastLogIndex,
                   int lastLogTerm){
  
}

void Server::ReplyVote(){
  if (m_term<) {
  
  }
}

// 随机计时器
void timer() {
  std::random_device rd;
  std::default_random_engine eng(rd());
  std::uniform_int_distribution<int> dist(150, 300);
  const auto &sleep = dist(eng);
  std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
}

void Server::RequestAppendEntries(int term, int leaderId, int prevLogIndex,
                                  std::vector<Log> &entries, int leaderCommit) {
  
}
void Server::ReplyAppendEntries() {}

void Server::ToLeader(){
  
}
void Server::ToCandidate(){
  
}
void Server::ToFollower(){
  
}
