class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int size = rooms.size();
    if (size==0) return false;
    vector<bool> visited_rooms;
    visited_rooms.resize(size,false);
    queue<int> keys_not_visited;

    //initialze
    visited_rooms[0]=true;
  
    for (int i = 0; i < rooms[0].size(); ++i) {
       if (rooms[0][i] != 0) keys_not_visited.push(rooms[0][i]);
    }

    int next_room;
    while (!keys_not_visited.empty()) {
      // pick up first key and visit the room 
      /*
       1) romove it from the keys_not_visited;
       2) visited room insert new room
       3) get the keys in the new room and update keys we have list, and new key.*/
      next_room = keys_not_visited.front();
      keys_not_visited.pop();
      visited_rooms[next_room] = true;
      //get new_keys
      for (int i = 0; i < rooms[next_room].size(); ++i) {
	if (!visited_rooms[rooms[next_room][i]]) keys_not_visited.push(rooms[next_room][i]);
      }
            
    }

    for (auto it: visited_rooms) {
      if (!it) return false;
    }

    return true;
  }
};
