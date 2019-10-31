using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PriorityQueue
{
    // node structure to support tree-searching algorithms
    public struct node
    {
        public int X;
        public int Y;
        public int totalCost;
        public int gCost;

        public node(int p1, int p2)
        {
            X = p1;
            Y = p2;
            totalCost = 0;
            gCost = 0;
        }

    }

    // Direction enumeration to support printing to screen

    enum Directions {left, right, up, down};

    class SolvePuzzle
    {
        private static int startX;
        private static int startY;
        private static int endX;
        private static int endY;


        static int Main(string[] args)
        {

            // taking input
            if (args.Length != 2)
            {
                Console.WriteLine("You must enter the filename and search algorithm.");
                return 1;
            }

            Puzzle newPuzzle = new Puzzle(args[0]);

            string[,] Map = newPuzzle.theMap;

            // getting start and end values
            Calculate(Map);
            
            // switch to select algorithm based on input
            switch (args[1])
            {
                case "AS":
                    if (checkGoal(AS(Map)))
                        Print(args[0], args[1], AS(Map));             
                    else
                        Console.Write("No solution found.");                  
                    break;

                case "BFS":
                    if (checkGoal(BFS(Map)))
                        Print(args[0], args[1], BFS(Map));
                    else
                        Console.Write("No solution found.");
                    break;

                case "DFS":
                    if (checkGoal(DFS(Map)))
                        Print(args[0], args[1], DFS(Map));
                    else
                        Console.Write("No solution found.");
                    break;

                case "GBFS":
                    if (checkGoal(GBFS(Map)))
                        Print(args[0], args[1], GBFS(Map));
                    else
                        Console.Write("No solution found.");
                    break;

                case "CUS1":
                    if (checkGoal(AS(Map)))
                        Print(args[0], args[1], AS(Map));
                    else
                        Console.Write("No solution found.");
                    break;

                case "CUS2":
                    if (checkGoal(AS(Map)))
                        Print(args[0], args[1], AS(Map));
                    else
                        Console.Write("No solution found.");
                    break;

                default:
                    break;
            }

            return 0;
        }

        // A* search
        public static List<node> AS(string[,] aMap)
        {
            // initalising
            node startNode = new node(startX, startY);
            node endNode = new node(endX, endY);
            node currentNode = startNode;

            Dictionary<node, node> Parents = new Dictionary<node, node>();
            List<node> exploredNodes = new List<node>();

            // priority queue to sort by cost
            PriorityQueue<int, node> q = new PriorityQueue<int, node>();

            // add start node to begin
            startNode.totalCost = CalcCostAS(startNode, startNode);
            q.Enqueue(startNode.totalCost, startNode);
          
            while (!(q.IsEmpty))
            {
                // get next in queue
                currentNode = q.Dequeue();

                // finished once we find goal
                if(aMap[currentNode.X, currentNode.Y] == aMap[endNode.X, endNode.Y])
                    return tracePath(currentNode, Parents);

                exploredNodes.Add(currentNode);

                foreach (node n in getNeighbours(currentNode, aMap))
                {
                    node newNode = n;

                    // calculating costs for algorithm
                    newNode.gCost = currentNode.gCost + 1; // total movement from start if moving to next node is current + 1
                    newNode.totalCost = CalcCostAS(currentNode, newNode);

                    int ng = currentNode.gCost + CalcCostAS(currentNode, newNode);
               
                    if (!(exploredNodes.Contains(newNode)))
                    {
                        // only enqueued if not explored or in queue
                        if ((!(q.Contains(newNode))))
                            q.Enqueue(newNode.totalCost, newNode);

                        // only optimal path if cheaper cost
                        if (ng >= newNode.gCost)
                            Parents[newNode] = currentNode;
                    }
                }

            }               
            return tracePath(currentNode, Parents);
        }

        // Breath-First Search
        public static List<node> BFS(string[,] aMap)
        {
            // initialising
            List<node> exploredNodes = new List<node>();
            Dictionary<node, node> Parents = new Dictionary<node, node>();

            List<node> Path = new List<node>();

            // queue for FIFO
            Queue<node> q = new Queue<node>();

            node startNode = new node(startX, startY);
            node currentNode = startNode;

            // add start node
            exploredNodes.Add(currentNode);
            q.Enqueue(currentNode);

            while(q.Any())
            {
                // get next in queue
                currentNode = q.Dequeue();

                // finished once we find goal
                if (aMap[currentNode.X, currentNode.Y] == aMap[endX, endY])
                    return tracePath(currentNode, Parents);
                
                foreach (node n in getNeighbours(currentNode, aMap))
                {
                    node newNode = n;

                    // only enqueue if not explored yet
                    if (!(exploredNodes.Contains(newNode)))
                    {
                        Parents[newNode] = currentNode;
                        q.Enqueue(newNode);                    
                    }
                }

                exploredNodes.Add(currentNode);
            }

            return tracePath(currentNode, Parents);
        }

        // Depth-First Search
        public static List<node> DFS(string[,] aMap)
        {
            // Initalising
            List<node> exploredNodes = new List<node>();
            Dictionary<node, node> Parents = new Dictionary<node, node>();
            Stack<node> s = new Stack<node>();

            node startNode = new node(startX, startY);
            node currentNode = startNode;

            // push start to stack
            s.Push(startNode);
          
            while (s.Any())
            {
                // pop for next node
                currentNode = s.Pop();

                // finished once we find goal
                if (aMap[currentNode.X, currentNode.Y] == aMap[endX, endY])
                    return tracePath(currentNode, Parents);

                // checking if explored first
                if (!(exploredNodes.Contains(currentNode)))
                {
                    // add it if not
                    exploredNodes.Add(currentNode);
                   
                    foreach (node n in getNeighbours(currentNode, aMap))
                    {
                        node newNode = n;
                        // if its not explored we can push to the stack
                        if (!(exploredNodes.Contains(newNode)))
                        {
                            Parents[newNode] = currentNode;
                            s.Push(newNode);
                        }                                          
                    }
                }
            }    
            return tracePath(currentNode, Parents); 
        }

        // Greedy Best-First search
        public static List<node> GBFS(string[,] aMap)
        {
            // initalising
            node startNode = new node(startX, startY);
            node endNode = new node(endX, endY);
            node currentNode = startNode;

            Dictionary<node, node> Parents = new Dictionary<node, node>();
            List<node> exploredNodes = new List<node>();
            
            Stack<node> s = new Stack<node>();

            // push startnode to stack
            startNode.totalCost = CalcCostGBFS(startNode);
            s.Push(startNode);
     

            while (s.Any())
            {
                // get current node by popping
                currentNode = s.Pop();

                // finished if found goal node
                if (aMap[currentNode.X, currentNode.Y] == aMap[endX, endY])
                   return tracePath(currentNode, Parents);

                exploredNodes.Add(currentNode);

                List<node> neighbours = getNeighbours(currentNode, aMap);
                neighbours.Reverse(); // reversing order so neighbours are in correct order for GBFS logic

                foreach (node n in neighbours)
                {
                    node newNode = n;

                    newNode.totalCost = CalcCostGBFS(newNode);

                    if (!(exploredNodes.Contains(newNode)))
                    {
                        // put the neighour in at the top of the stack with the parent behind it
                        // when it found a cheaper cost
                        if (newNode.totalCost <= currentNode.totalCost)
                        {
                            s.Push(currentNode);
                            s.Push(newNode);
                            Parents[newNode] = currentNode;
                            break; // found better cost so we break here
                        }
                        // otherwise, keep looking
                        else
                        {
                            s.Push(newNode);
                            Parents[newNode] = currentNode;
                        }               
                    }
                }
            }

            return tracePath(currentNode, Parents);
        }

        public static List<node> CUS1(string[,] aMap)
        {
            List<node> Path = new List<node>();
            return Path;
        }

        public static List<node> CUS2(string[,] aMap)
        {
            List<node> Path = new List<node>();
            return Path;
        }

        public static void Calculate(string[,] aArray)
        {
            // get start and end specification
            for(int i = 0; i < aArray.GetLength(0); i++)
            {
                for (int j = 0; j < aArray.GetLength(1); j++)
                {
                    if (aArray[i, j] == "S")
                    {
                        startX = i;
                        startY = j;
                    }

                    if (aArray[i, j] == "E")
                    {
                        endX = i;
                        endY = j;
                    }
                }
            }
        }

        public static void Print(string aFilename, string aAlgorithm, List<node> aPath)
        {
                      
            List<Directions> lDirections = new List<Directions>();

            // printing output
            Console.WriteLine("Searched " + aFilename + " using " + aAlgorithm + " with " + (aPath.Count-1) + " Nodes traversed.");
            Console.WriteLine("");
            Console.Write("Path:> ");

            // iterate path and use directions enum to print directions
            for (int i = 0; i < aPath.Count()-1; i++)
            {
                //if (aPath.ElementAt(i).X == aPath.Last().X && aPath.ElementAt(i).Y == aPath.Last().Y)
              //  {
                //    break;
              //  }

                if (aPath.ElementAt(i).X > aPath.ElementAt(i+1).X)
                {
                    lDirections.Add(Directions.left);
                }

                if (aPath.ElementAt(i).X < aPath.ElementAt(i + 1).X)
                {
                    lDirections.Add(Directions.right);
                }

                if (aPath.ElementAt(i).Y > aPath.ElementAt(i + 1).Y)
                {
                    lDirections.Add(Directions.up);
                }

                if (aPath.ElementAt(i).Y < aPath.ElementAt(i + 1).Y)
                {
                    lDirections.Add(Directions.down);
                }

                Console.Write(lDirections.Last() + "; ");
            }
            Console.WriteLine("");
        }

        public static int CalcCostGBFS(node aNode)
        {
            // Calculate cost from node to end
            return Math.Abs(endX - aNode.X) + Math.Abs(endY - aNode.Y);
        }

        // Calculate F (totalCost) of next node
        public static int CalcCostAS(node aCurrentNode, node aNewNode)
        {
            int H = Math.Abs(endX - aNewNode.X) + Math.Abs(endY - aNewNode.Y);

            int G = aNewNode.gCost;

            int F = H + G; // A* algorithm f = g + h

            return F;
        }

        public static List<node> getNeighbours(node aNode, string[,] aMap)
        {
            // using a list as this allows for an implementation if over 4 neighbours if desired

            List<node> neighbours = new List<node>();

            // order is up, left, down, right
            // order here must be reverse due to how priority queue works for informed searches.
            
            // RIGHT
            if (((aNode.X + 1) != aMap.GetLength(0)) && (aMap[aNode.X + 1, aNode.Y] != "#"))
            {
                node newNode = new node(aNode.X + 1, aNode.Y);
                neighbours.Add(newNode);
            }

            // DOWN
            if (((aNode.Y + 1) != aMap.GetLength(1)) && (aMap[aNode.X, aNode.Y + 1] != "#"))
            {
                node newNode = new node(aNode.X, aNode.Y + 1);
                neighbours.Add(newNode);
            }

            // LEFT
            if ((!((aNode.X - 1) < 0)) && (aMap[aNode.X - 1, aNode.Y] != "#"))
            {
                node newNode = new node(aNode.X - 1, aNode.Y);
                neighbours.Add(newNode);
            }

            // UP
            if ((!((aNode.Y - 1) < 0)) && (aMap[aNode.X, aNode.Y - 1] != "#"))
            {
                node newNode = new node(aNode.X, aNode.Y - 1);
                neighbours.Add(newNode);
            }


            return neighbours;
        }

        // trace from end to start and return a path from start to end
        public static List<node> tracePath(node aNode, Dictionary<node,node> aParents)
        {
            node startNode = new node(startX, startY);
            List<node> Path = new List<node>();

            node newNode = aNode;

            while(aParents.ContainsKey(newNode))
            {
                Path.Add(newNode);
                newNode = aParents[newNode];
            }

            Path.Add(newNode);
        
            Path.Reverse(); // so its in order of start to end

            return Path;
        }

        // check if that path ends at the endnode, if not in the main switch statement,
        // no solution will be printed to the user
        public static bool checkGoal(List<node> aList)
        {
            if ((aList.Last().X == endX) && (aList.Last().Y == endY))
                return true;
            else
                return false;
        }
    }
}
