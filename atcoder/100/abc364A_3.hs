main :: IO ()
main = do
  n <- readLn :: IO Int
  result <- readLines n 0 "Yes"
  putStrLn result

readLines :: Int -> Int -> String -> IO String
readLines 0 _ ans = return ans
readLines n sweets ans = do
  s <- getLine
  if sweets >= 2 then
    readLines (n-1) sweets "No"
  else do
    readLines (n - 1) (if s == "sweet" then sweets + 1 else 0) ans
