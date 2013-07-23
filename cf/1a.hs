
main = do
  input <- getContents
  let
    [a,b,c] = map read (words input)::[Integer]
  putStrLn $ show (((a+c-1) `div` c) * ((b+c-1) `div` c))
