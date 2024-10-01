import Data.Char


main :: IO ()
main = do
  n <- getLine
  let numLines = read n :: Int
  readLines (numLines, 0, "Yes")


readLines :: (Int, Int, String) -> IO()
readLines (n, sweets, ans) = do
  if n == 0 then
    putStrLn ans
  else do
    s <- getLine
    if sweets >= 2 then
      readLines(n-1, sweets, "No")
    else do
      if s == "sweet" then
        readLines (n-1, sweets+1, ans)
      else do
        readLines (n-1, 0, ans)
