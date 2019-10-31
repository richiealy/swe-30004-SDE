class AI(object):
    WIN_SET = (
        (0, 1, 2), (3, 4, 5), (6, 7, 8), (0, 3, 6),
        (1, 4, 7), (2, 5, 8), (0, 4, 8), (2, 4, 6)
    )

    def __init__(self, board, ai_type):
        self.board = board
        self.ai_type = ai_type

    def getWinner(self) :
        board = self.board
        for player in ('x', 'o') :
            for combos in self.WIN_SET :
                if board[combos[0]] == player and board[combos[1]] == player and board[combos[2]] == player :
                    return player

        if ' ' not in board:
            return 'tie'
        return None

    def get_possible_moves(self):
        board = self.board

        # Create list of possible 
        possible_moves = []

        for i in range(9):
            if board[i] == ' ':
                possible_moves.append(i)

        return possible_moves

    def mini_max(self, player, depth = 0):
        board = self.board

        possible_moves = self.get_possible_moves()
         
        if player == 'o':
            best_score = -10
        else:
            best_score = 10

        if self.getWinner() == 'o':
            return 10 - depth, None
        elif self.getWinner() == 'x':
            return -10 + depth, None
        elif self.getWinner() == "tie":
            return 0, None

        for move in possible_moves:
            board[move] = player

            if player == 'o': # AI
                move_score, _ = self.mini_max('x', depth+1)
            else:
                move_score, _ = self.mini_max('o', depth+1)
            
            # Reset
            board[move] = ' '
            if player == 'o':
                if move_score > best_score:
                    best_score, best_move = move_score, move
            else:
                if move_score < best_score:
                    best_score, best_move = move_score, move

        # Keep track of the move
        return best_score, best_move     

    def dumb_ai(self):
        possible_moves = self.get_possible_moves()

        # Take center if not taken
        if 4 in possible_moves:
            return 4

        # Otherwise do a corner move
        for move in 0,2,6,8:
            if move in possible_moves:
                return move

        # Otherwise do an edge move
        for move in possible_moves:
            return move


    def do_turn(self):
        ai_type = self.ai_type

        if ai_type == 'smart':
            return self.mini_max('o')
        elif ai_type == 'dumb':
            return self.dumb_ai()