
main = do
  n <- readLn :: IO Int
  let
    res = if ((n `mod` 2 == 0) && (n >= 4))
            then "YES"
            else "NO"
  putStrLn res
    
