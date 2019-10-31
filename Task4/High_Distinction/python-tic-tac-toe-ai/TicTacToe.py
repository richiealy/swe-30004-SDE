from AI import *

class TicTacToe(object):
    WIN_SET = (
        (0, 1, 2), (3, 4, 5), (6, 7, 8), (0, 3, 6),
        (1, 4, 7), (2, 5, 8), (0, 4, 8), (2, 4, 6)
    )

    HR = '-' * 40

    def __init__(self):
        self.board = [' '] * 9
        self.players = {'x': 'Human', 'o': 'Smart AI'}
        self.winner = None
        self.playing = True
        self.move = None
        self.ai_mode = None
        self.spectating = False
        self.current_player = 'x'
        print('Tic Tac Toe')
        print(self.HR)
        self.show_help()
        self.choose_mode()
        self.render()

    def _is_move_valid(self):
            self.move = int(self.move)

            if self.board[self.move] == ' ':
                return True
            else:
                print('** Move is not valid, this space is taken or the position doesn\'t exist. **')
                return False

    def _get_board_state(self):
        board = self.board
        for row in self.WIN_SET:
            if board[row[0]] == board[row[1]] == board[row[2]] != ' ': # If there is any 3 in a row of 'x' or 'o' as defned in WIN_SET
                return board[row[0]] # return an 'x' or 'o' to indicate winner

        if ' ' not in board:
            return 'tie'

        return None

    def choose_mode(self):
        print('1. Play vs the smart AI')
        print('2. Play vs the dumb AI')
        print('3. Watch the dumb AI play for you vs the smart AI')

        choice = int(input('Enter your selection [1-3] >> '))

        if choice == 1:
            self.ai_mode = 'smart'
        elif choice == 2:
            self.ai_mode = 'dumb'
        elif choice == 3:
            self.spectating = True
            self.players['x'] = 'Dumb AI'
            self.ai_mode = 'smart'
        else:
            print(self.HR)
            print('Invalid input')
            print(self.HR)
            self.choose_mode()

    def get_human_move(self):
        return input('[0-8] >> ')

    def get_dumb_ai_move(self):
        board = self.board
        # Deep copy of board so that the mini_max function doesn't modify the original board
        board_copy = board[:]

        ai = AI(board_copy, 'dumb')
        return ai.do_turn()

    def get_smart_ai_move(self):
        board = self.board
        # Deep copy of board so that the mini_max function doesn't modify the original board
        board_copy = board[:]

        ai = AI(board_copy, self.ai_mode)
        if self.ai_mode == 'smart':
            val, best_move = ai.do_turn()
            return best_move
        else:
            return ai.do_turn()
                
    def process(self):
        if self.current_player == 'x': # Player move / Dumb AI moves
            if self.spectating == False:
                self.move = self.get_human_move()
            else:
                self.move = self.get_dumb_ai_move()
        else: # Smart AI Move
            self.move = self.get_smart_ai_move()

    def update(self):
        if self._is_move_valid():
            self.board[self.move] = self.current_player
            self.winner = self._get_board_state()
            if self.current_player == 'x':
                self.current_player = 'o'
            else:
                self.current_player = 'x'
        else:
            print('Try again')

    def render(self):
        board = self.board
        print(self.HR)
        print('    %s | %s | %s' % tuple(board[:3]))
        print('   -----------')
        print('    %s | %s | %s' % tuple(board[3:6]))
        print('   -----------')
        print('    %s | %s | %s' % tuple(board[6:]))

        if self.winner is None:
            print('Current player: %s' % self.players[self.current_player])
            
    def show_help(self):
        message = '''
    To make a move enter a number between 0 - 8 and press enter.
    The number corresponds to a board position as illustrated:

        0 | 1 | 2
        ---------
        3 | 4 | 5
        ---------
        6 | 7 | 8
        '''
        print(message)
        print(self.HR)

    def print_result(self):
        if self.winner == 'tie':
            print("The game ended in a tie...")
        else:
            print('%s is the winner!' % self.players[self.winner])
        print('Game Finished!')

#==============================================================================
# Separate the running of the game using a __name__ test. Allows the use of this
# file as an imported module
#==============================================================================

if __name__ == '__main__':
    game = TicTacToe()

    while game.winner is None:
        game.process()
        game.update()
        game.render()

    game.print_result()