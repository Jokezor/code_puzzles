import Data.Char


main :: IO ()
main = do
  n <- getLine
  let numLines = read n :: Int
  eat_ind <- eatDishes (numLines, 0, 0)
  if eat_ind == numLines then
    putStrLn "Yes"
  else do
    putStrLn "No"


eatDishes :: (Int, Int, Int) -> IO Int
eatDishes (n, sweets, ans) = do
  if n == 0 then
    return ans
  else do
    s <- getLine
    if sweets >= 2 then
      eatDishes(n-1, sweets, ans)
    else if s == "sweet" then
        eatDishes (n-1, sweets+1, ans+1)
    else
        eatDishes (n-1, 0, ans+1)
