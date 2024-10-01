main :: IO ()
main = readLn >>= \n -> go n 0 "Yes" >>= putStrLn

go :: Int -> Int -> String -> IO String
go 0 _ a = return a
go n s a = getLine >>= \x -> go (n-1) (if x == "sweet" then s+1 else 0) (if s >= 2 then "No" else a)
